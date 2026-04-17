/**
 * @file ur_kinematics.cpp
 * @brief URKinematics implementation for UR5e forward/inverse kinematics,
 *        Jacobian computation, velocity servoing, and singularity handling.
 *
 * Pure math - NO ROS dependencies. Uses Eigen throughout.
 */

#include "ur_robot_manager/utils/ur_kinematics.h"

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

// ===================================================================
// Constructor
// ===================================================================
URKinematics::URKinematics()
{
    // UR5e DH parameters (metres)
    d1_ = 0.1626908436;
    a2_ = -0.4250156423;
    a3_ = -0.3921146227;
    d4_ = 0.1335368450;
    d5_ = 0.0995866193;
    d6_ = 0.0994997837;

    // No tool TCP by default
    T_flange_tcp_ = Eigen::Matrix4d::Identity();
}

// ===================================================================
// Tool TCP
// ===================================================================
void URKinematics::setToolTCP(const Eigen::Vector3d& t_tcp, const Eigen::Vector3d& rvec_tcp)
{
    T_flange_tcp_ = Eigen::Matrix4d::Identity();
    T_flange_tcp_.block<3,3>(0,0) = rvecToR(rvec_tcp);
    T_flange_tcp_.block<3,1>(0,3) = t_tcp;
}

// ===================================================================
// Rotation helpers (private)
// ===================================================================
Eigen::Matrix4d URKinematics::Rx(double a)
{
    Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
    double c = std::cos(a), s = std::sin(a);
    T(1,1) = c;  T(1,2) = -s;
    T(2,1) = s;  T(2,2) =  c;
    return T;
}

Eigen::Matrix4d URKinematics::RzTz(double th, double dz)
{
    Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
    double c = std::cos(th), s = std::sin(th);
    T(0,0) = c;  T(0,1) = -s;
    T(1,0) = s;  T(1,1) =  c;
    T(2,3) = dz;
    return T;
}

// ===================================================================
// Rodrigues formula: rotation vector <-> rotation matrix
// ===================================================================
Eigen::Matrix3d URKinematics::rodrigues(const Eigen::Vector3d& axis, double ang)
{
    if (std::abs(ang) < 1e-12) {
        return Eigen::Matrix3d::Identity();
    }
    Eigen::Vector3d k = axis.normalized();
    Eigen::Matrix3d K;
    K <<     0, -k.z(),  k.y(),
         k.z(),      0, -k.x(),
        -k.y(),  k.x(),      0;
    return Eigen::Matrix3d::Identity() + std::sin(ang) * K +
           (1.0 - std::cos(ang)) * K * K;
}

Eigen::Matrix3d URKinematics::rvecToR(const Eigen::Vector3d& rvec)
{
    double theta = rvec.norm();
    if (theta < 1e-12) {
        return Eigen::Matrix3d::Identity();
    }
    return rodrigues(rvec / theta, theta);
}

Eigen::Vector3d URKinematics::RToRvec(const Eigen::Matrix3d& R)
{
    Eigen::AngleAxisd aa(R);
    return aa.angle() * aa.axis();
}

Eigen::Vector3d URKinematics::unwrapRvec(const Eigen::Vector3d& rvec_prev,
                                          const Eigen::Vector3d& rvec_now)
{
    double theta = rvec_now.norm();
    if (theta < 1e-12) return rvec_now;

    Eigen::Vector3d k = rvec_now / theta;

    // Candidate 1: as-is
    Eigen::Vector3d c1 = rvec_now;
    // Candidate 2: equivalent with flipped axis
    double theta2 = 2.0 * M_PI - theta;
    Eigen::Vector3d c2 = -k * theta2;

    return ((c1 - rvec_prev).norm() <= (c2 - rvec_prev).norm()) ? c1 : c2;
}

// ===================================================================
// Pose <-> Homogeneous transform
// ===================================================================
Eigen::Matrix4d URKinematics::poseToT(const PoseAA& pose)
{
    Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
    T.block<3,3>(0,0) = rvecToR(pose.rvec);
    T.block<3,1>(0,3) = pose.p;
    return T;
}

PoseAA URKinematics::TToPose(const Eigen::Matrix4d& T)
{
    PoseAA pose;
    pose.p = T.block<3,1>(0,3);
    pose.rvec = RToRvec(T.block<3,3>(0,0));
    return pose;
}

// ===================================================================
// Forward kinematics (flange)
// ===================================================================
Eigen::Matrix4d URKinematics::forwardKinematics(const Eigen::Matrix<double,6,1>& q,
                                                  std::vector<Eigen::Matrix4d>* Tlist) const
{
    double q1 = q(0), q2 = q(1), q3 = q(2);
    double q4 = q(3), q5 = q(4), q6 = q(5);

    double s1 = std::sin(q1), c1 = std::cos(q1);
    double s2 = std::sin(q2), c2 = std::cos(q2);
    double s3 = std::sin(q3), c3 = std::cos(q3);
    double s4 = std::sin(q4), c4 = std::cos(q4);
    double s5 = std::sin(q5), c5 = std::cos(q5);
    double s6 = std::sin(q6), c6 = std::cos(q6);

    double s23 = std::sin(q2 + q3), c23 = std::cos(q2 + q3);

    // Position
    double px = d6_ * (c1*c23*c4*s5 + c1*s23*c5 + s1*s4*s5) +
                d5_ * (c1*s23) + d4_ * s1 +
                a3_ * c1 * c23 + a2_ * c1 * c2;
    double py = d6_ * (s1*c23*c4*s5 + s1*s23*c5 - c1*s4*s5) +
                d5_ * (s1*s23) - d4_ * c1 +
                a3_ * s1 * c23 + a2_ * s1 * c2;
    double pz = d6_ * (-s23*c4*s5 + c23*c5) +
                d5_ * c23 + d1_ +
                a3_ * (-s23) + a2_ * (-s2);

    // Rotation matrix (simplified DH product)
    Eigen::Matrix3d R;
    R(0,0) = c6*(c1*c23*c4*c5 + c1*s23*(-s5) + s1*s4*c5) - s6*(c1*c23*(-s4) + s1*c4);
    R(0,1) = -s6*(c1*c23*c4*c5 + c1*s23*(-s5) + s1*s4*c5) - c6*(c1*c23*(-s4) + s1*c4);
    R(0,2) = c1*c23*c4*s5 + c1*s23*c5 + s1*s4*s5;

    R(1,0) = c6*(s1*c23*c4*c5 + s1*s23*(-s5) - c1*s4*c5) - s6*(s1*c23*(-s4) - c1*c4);
    R(1,1) = -s6*(s1*c23*c4*c5 + s1*s23*(-s5) - c1*s4*c5) - c6*(s1*c23*(-s4) - c1*c4);
    R(1,2) = s1*c23*c4*s5 + s1*s23*c5 - c1*s4*s5;

    R(2,0) = c6*(-s23*c4*c5 + c23*(-s5)) - s6*(-s23*(-s4));
    R(2,1) = -s6*(-s23*c4*c5 + c23*(-s5)) - c6*(-s23*(-s4));
    R(2,2) = -s23*c4*s5 + c23*c5;

    Eigen::Matrix4d T06 = Eigen::Matrix4d::Identity();
    T06.block<3,3>(0,0) = R;
    T06.block<3,1>(0,3) = Eigen::Vector3d(px, py, pz);

    if (Tlist) {
        Tlist->clear();
        Tlist->reserve(7);

        Eigen::Matrix4d T01 = RzTz(q1, d1_);

        Eigen::Matrix4d T12 = Eigen::Matrix4d::Identity();
        T12(0,0) = c2; T12(0,1) = -s2; T12(0,3) = a2_ * c2;
        T12(1,0) = s2; T12(1,1) =  c2; T12(1,3) = a2_ * s2;

        Eigen::Matrix4d T23 = Eigen::Matrix4d::Identity();
        T23(0,0) = c3; T23(0,1) = -s3; T23(0,3) = a3_ * c3;
        T23(1,0) = s3; T23(1,1) =  c3; T23(1,3) = a3_ * s3;

        Eigen::Matrix4d T34 = RzTz(q4, d4_);

        Eigen::Matrix4d T45 = Eigen::Matrix4d::Identity();
        T45(0,0) = c5; T45(0,2) = s5;
        T45(1,1) = 1.0;
        T45(2,0) = -s5; T45(2,2) = c5;
        T45(2,3) = d5_;

        Eigen::Matrix4d T56 = Eigen::Matrix4d::Identity();
        T56(0,0) = c6; T56(0,1) = -s6;
        T56(1,0) = s6; T56(1,1) = c6;
        T56(2,3) = d6_;

        Tlist->push_back(Eigen::Matrix4d::Identity()); // T_base
        Tlist->push_back(T01);
        Tlist->push_back(T01 * T12);
        Tlist->push_back(T01 * T12 * T23);
        Tlist->push_back(T01 * T12 * T23 * T34);
        Tlist->push_back(T01 * T12 * T23 * T34 * T45);
        Tlist->push_back(T06);
    }

    return T06;
}

// ===================================================================
// Forward kinematics (TCP)
// ===================================================================
Eigen::Matrix4d URKinematics::forwardKinematicsTCP(const Eigen::Matrix<double,6,1>& q,
                                                    std::vector<Eigen::Matrix4d>* Tlist) const
{
    Eigen::Matrix4d T_flange = forwardKinematics(q, Tlist);
    return T_flange * T_flange_tcp_;
}

// ===================================================================
// Geometric Jacobian at TCP
// ===================================================================
Eigen::Matrix<double, 6, 6> URKinematics::geometricJacobianTCP(
    const Eigen::Matrix<double,6,1>& q) const
{
    // Numerical Jacobian via finite differences
    const double dq = 1e-8;
    Eigen::Matrix<double, 6, 6> J;

    Eigen::Matrix4d T0 = forwardKinematicsTCP(q);
    Eigen::Vector3d p0 = T0.block<3,1>(0,3);
    Eigen::Matrix3d R0 = T0.block<3,3>(0,0);

    for (int i = 0; i < 6; ++i) {
        Eigen::Matrix<double,6,1> q_plus = q;
        q_plus(i) += dq;
        Eigen::Matrix4d T_plus = forwardKinematicsTCP(q_plus);
        Eigen::Vector3d p_plus = T_plus.block<3,1>(0,3);

        for (int j = 0; j < 3; ++j) {
            J(j, i) = (p_plus(j) - p0(j)) / dq;
        }
        // Angular part via rotation difference
        Eigen::Matrix3d dR = T_plus.block<3,3>(0,0) * R0.transpose();
        Eigen::Vector3d domega = RToRvec(dR) / dq;
        J(3, i) = domega.x();
        J(4, i) = domega.y();
        J(5, i) = domega.z();
    }
    return J;
}

// ===================================================================
// Damped Least Squares inverse
// ===================================================================
Eigen::Matrix<double, 6, 6> URKinematics::dlsInverse(
    const Eigen::Matrix<double, 6, 6>& J, double lambda)
{
    // J^# = J^T (J J^T + lambda^2 I)^{-1}
    Eigen::Matrix<double, 6, 6> JJT = J * J.transpose();
    Eigen::Matrix<double, 6, 6> I = Eigen::Matrix<double, 6, 6>::Identity();
    return J.transpose() * (JJT + lambda * lambda * I).inverse();
}

// ===================================================================
// Velocity servo step
// ===================================================================
void URKinematics::velocityServoStep(const Eigen::Matrix<double,6,1>& q,
                                      const Eigen::Matrix4d& T_des,
                                      double Kp, double Ko, double lam, double dt,
                                      double qdot_limit,
                                      const std::string& nullspace_mode,
                                      Eigen::Matrix<double,6,1>& q_next,
                                      Eigen::Matrix<double,6,1>& qdot,
                                      ServoStats* out) const
{
    (void)nullspace_mode;  // reserved for future use

    Eigen::Matrix4d T_cur = forwardKinematicsTCP(q);

    // Position error
    Eigen::Vector3d ep = T_des.block<3,1>(0,3) - T_cur.block<3,1>(0,3);

    // Orientation error
    Eigen::Matrix3d Re = T_des.block<3,3>(0,0) * T_cur.block<3,3>(0,0).transpose();
    Eigen::Vector3d eo = RToRvec(Re);

    // Construct twist
    Eigen::Matrix<double,6,1> twist;
    twist.head<3>() = Kp * ep;
    twist.tail<3>() = Ko * eo;

    // Jacobian and DLS inverse
    Eigen::Matrix<double,6,6> J = geometricJacobianTCP(q);
    Eigen::Matrix<double,6,6> J_inv = dlsInverse(J, lam);

    qdot = J_inv * twist;

    // Clamp joint velocities
    double max_qdot = qdot.cwiseAbs().maxCoeff();
    if (max_qdot > qdot_limit && max_qdot > 1e-10) {
        qdot *= qdot_limit / max_qdot;
    }

    q_next = q + qdot * dt;

    if (out) {
        out->pos_err = ep.norm();
        out->ori_err = eo.norm();
        out->manip = manipulability(J);
    }
}

// ===================================================================
// Private helper functions
// ===================================================================
double URKinematics::acos_biased(double x, int sign, double eps)
{
    (void)eps;
    x = std::clamp(x, -1.0, 1.0);
    double val = std::acos(x);
    return (sign >= 0) ? val : -val;
}

Eigen::Matrix4d URKinematics::fastInverse(const Eigen::Matrix4d& T)
{
    Eigen::Matrix4d T_inv = Eigen::Matrix4d::Identity();
    T_inv.block<3,3>(0,0) = T.block<3,3>(0,0).transpose();
    T_inv.block<3,1>(0,3) = -T.block<3,3>(0,0).transpose() * T.block<3,1>(0,3);
    return T_inv;
}

double URKinematics::wrap_to_2pi(double a)
{
    a = std::fmod(a, 2.0 * M_PI);
    if (a < 0) a += 2.0 * M_PI;
    return a;
}

double URKinematics::adjust_angle_to_closest(double a, double ref)
{
    double diff = a - ref;
    diff = std::fmod(diff + M_PI, 2.0 * M_PI) - M_PI;
    return ref + diff;
}

Eigen::Matrix<double,6,1> URKinematics::adjust_and_wrap(
    const Eigen::Matrix<double,6,1>& q,
    const Eigen::Matrix<double,6,1>* q_current,
    bool do_adjust, bool do_wrap) const
{
    Eigen::Matrix<double,6,1> result = q;
    for (int i = 0; i < 6; ++i) {
        if (do_wrap) {
            result(i) = wrap_to_2pi(result(i));
        }
        if (do_adjust && q_current) {
            result(i) = adjust_angle_to_closest(result(i), (*q_current)(i));
        }
    }
    return result;
}

double URKinematics::scoreSolution(const Eigen::Matrix<double,6,1>& q,
                                    const Eigen::Matrix4d& T_target,
                                    const Eigen::Matrix<double,6,1>& q_current) const
{
    (void)T_target;
    static const double weights[6] = {1.0, 1.0, 1.0, 1.0, 1.0, 0.5};
    double score = 0.0;
    for (int i = 0; i < 6; ++i) {
        double diff = q(i) - q_current(i);
        diff = std::fmod(diff + M_PI, 2.0 * M_PI) - M_PI;
        score += weights[i] * diff * diff;
    }
    return score;
}

// ===================================================================
// Solve a single IK configuration (private member)
// ===================================================================
bool URKinematics::solveIKConfig(
    const Eigen::Matrix4d& T06,
    const Eigen::Matrix<double,6,1>* q_current,
    int shoulder_sign, int elbow_sign, int wrist_sign,
    Eigen::Matrix<double,6,1>& th_out) const
{
    (void)q_current;
    th_out.setZero();

    Eigen::Vector3d p05 = T06.block<3,1>(0,3) - d6_ * T06.block<3,3>(0,0).col(2);

    // Joint 1
    double psi = std::atan2(p05.y(), p05.x());
    double r_sq = p05.x() * p05.x() + p05.y() * p05.y();
    if (r_sq < d4_ * d4_) return false;
    double phi = std::acos(std::clamp(d4_ / std::sqrt(r_sq), -1.0, 1.0));

    if (shoulder_sign >= 0) {
        th_out(0) = psi + phi + M_PI_2;
    } else {
        th_out(0) = psi - phi + M_PI_2;
    }

    // Joint 5
    double s1 = std::sin(th_out(0)), c1 = std::cos(th_out(0));
    double q5_arg = (p05.x() * s1 - p05.y() * c1 - d4_) / d6_;
    if (std::abs(q5_arg) > 1.0 + 1e-8) return false;
    q5_arg = std::clamp(q5_arg, -1.0, 1.0);

    if (wrist_sign >= 0) {
        th_out(4) = std::acos(q5_arg);
    } else {
        th_out(4) = -std::acos(q5_arg);
    }

    // Joint 6
    double s5 = std::sin(th_out(4));
    if (std::abs(s5) < 1e-10) {
        th_out(5) = 0.0;  // Singularity: wrist aligned
    } else {
        Eigen::Vector3d Xhat = T06.block<3,3>(0,0).col(0);
        Eigen::Vector3d Yhat = T06.block<3,3>(0,0).col(1);
        double num   = (-Xhat.x() * s1 + Xhat.y() * c1);
        double denom = ( Yhat.x() * s1 - Yhat.y() * c1);
        th_out(5) = std::atan2(num / s5, denom / s5);
    }

    // Joints 2, 3, 4 via the planar sub-problem
    double c6 = std::cos(th_out(5)), s6 = std::sin(th_out(5));
    Eigen::Matrix4d T01 = RzTz(th_out(0), d1_);
    Eigen::Matrix4d T45 = Eigen::Matrix4d::Identity();
    {
        double c5v = std::cos(th_out(4));
        double s5v = std::sin(th_out(4));
        T45(0,0) = c5v; T45(0,2) = s5v;
        T45(1,1) = 1.0;
        T45(2,0) = -s5v; T45(2,2) = c5v;
        T45(2,3) = d5_;
    }
    Eigen::Matrix4d T56 = Eigen::Matrix4d::Identity();
    {
        T56(0,0) = c6; T56(0,1) = -s6;
        T56(1,0) = s6; T56(1,1) = c6;
        T56(2,3) = d6_;
    }

    Eigen::Matrix4d T14 = fastInverse(T01) * T06 * fastInverse(T45 * T56);

    double p14x = T14(0, 3);
    double p14z = T14(2, 3);

    double c3_arg = (p14x * p14x + p14z * p14z - a2_ * a2_ - a3_ * a3_) /
                    (2.0 * a2_ * a3_);
    if (std::abs(c3_arg) > 1.0 + 1e-8) return false;
    c3_arg = std::clamp(c3_arg, -1.0, 1.0);

    if (elbow_sign >= 0) {
        th_out(2) = std::acos(c3_arg);
    } else {
        th_out(2) = -std::acos(c3_arg);
    }

    double s3 = std::sin(th_out(2)), c3 = std::cos(th_out(2));
    th_out(1) = std::atan2(-p14z, -p14x) -
                std::atan2(a3_ * s3, a2_ + a3_ * c3);

    // Joint 4
    Eigen::Matrix4d T12 = Eigen::Matrix4d::Identity();
    {
        double c2 = std::cos(th_out(1)), s2_v = std::sin(th_out(1));
        T12(0,0) = c2; T12(0,1) = -s2_v; T12(0,3) = a2_ * c2;
        T12(1,0) = s2_v; T12(1,1) = c2; T12(1,3) = a2_ * s2_v;
    }
    Eigen::Matrix4d T23 = Eigen::Matrix4d::Identity();
    {
        T23(0,0) = c3; T23(0,1) = -s3; T23(0,3) = a3_ * c3;
        T23(1,0) = s3; T23(1,1) = c3; T23(1,3) = a3_ * s3;
    }
    Eigen::Matrix4d T34 = fastInverse(T12 * T23) * T14;
    th_out(3) = std::atan2(T34(1, 0), T34(0, 0));

    return true;
}

// ===================================================================
// Inverse kinematics: 8-configuration solver
// ===================================================================
void URKinematics::inverseKinematics8(
    const Eigen::Matrix4d& T06,
    const Eigen::Matrix<double,6,1>* q_current,
    std::array<Eigen::Matrix<double,6,1>,8>& sols,
    std::array<bool,8>& valid) const
{
    int configs[8][3] = {
        { 1,  1,  1},
        { 1,  1, -1},
        { 1, -1,  1},
        { 1, -1, -1},
        {-1,  1,  1},
        {-1,  1, -1},
        {-1, -1,  1},
        {-1, -1, -1}
    };

    for (int i = 0; i < 8; ++i) {
        valid[i] = solveIKConfig(T06, q_current,
                                  configs[i][0], configs[i][1], configs[i][2],
                                  sols[i]);
    }
}

// ===================================================================
// Pick best from 8 IK solutions
// ===================================================================
std::pair<Eigen::Matrix<double,6,1>, int> URKinematics::pickBestFrom8(
    const Eigen::Matrix4d& T_target,
    const std::array<Eigen::Matrix<double,6,1>,8>& sols,
    const std::array<bool,8>& valid,
    const Eigen::Matrix<double,6,1>& q_current) const
{
    double best_score = std::numeric_limits<double>::max();
    int best_idx = -1;
    Eigen::Matrix<double,6,1> q_best = Eigen::Matrix<double,6,1>::Zero();

    for (int i = 0; i < 8; ++i) {
        if (!valid[i]) continue;

        Eigen::Matrix<double,6,1> adjusted = adjust_and_wrap(sols[i], &q_current, true, true);
        double s = scoreSolution(adjusted, T_target, q_current);
        if (s < best_score) {
            best_score = s;
            q_best = adjusted;
            best_idx = i;
        }
    }
    return {q_best, best_idx};
}

// ===================================================================
// Manipulability measure
// ===================================================================
double URKinematics::manipulability(const Eigen::Matrix<double,6,6>& J)
{
    Eigen::Matrix<double, 6, 6> JJT = J * J.transpose();
    return std::sqrt(std::max(0.0, JJT.determinant()));
}

// ===================================================================
// TCP target -> flange target (remove tool offset)
// ===================================================================
Eigen::Matrix4d URKinematics::tcpTargetToFlangeTarget(const Eigen::Matrix4d& T_tcp) const
{
    return T_tcp * fastInverse(T_flange_tcp_);
}

// ===================================================================
// Best IK for a TCP pose
// ===================================================================
bool URKinematics::ikBestForTCPPose(const Eigen::Matrix4d& T_tcp,
                                     const Eigen::Matrix<double,6,1>& q_current,
                                     Eigen::Matrix<double,6,1>& q_best,
                                     int* best_index) const
{
    Eigen::Matrix4d T_flange = tcpTargetToFlangeTarget(T_tcp);

    std::array<Eigen::Matrix<double,6,1>,8> sols;
    std::array<bool,8> valid;
    inverseKinematics8(T_flange, &q_current, sols, valid);

    auto result = pickBestFrom8(T_flange, sols, valid, q_current);
    if (result.second < 0) return false;

    q_best = result.first;
    if (best_index) *best_index = result.second;
    return true;
}

// ===================================================================
// Solve twist with prioritized task decomposition
// ===================================================================
void URKinematics::solveTwistPrioritized(const Eigen::Matrix<double,6,1>& q,
                                          const Eigen::Matrix<double,6,1>& twist_base,
                                          double lambda_v, double lambda_w,
                                          Eigen::Matrix<double,6,1>& qdot_out,
                                          double alpha_cancel) const
{
    Eigen::Matrix<double,6,6> J = geometricJacobianTCP(q);

    // Split Jacobian into linear (v) and angular (w) parts
    Eigen::Matrix<double,3,6> Jv = J.topRows<3>();
    Eigen::Matrix<double,3,6> Jw = J.bottomRows<3>();

    // Primary: linear velocity
    Eigen::Matrix<double,3,3> JvJvT = Jv * Jv.transpose();
    Eigen::Matrix3d I3 = Eigen::Matrix3d::Identity();
    Eigen::Matrix<double,6,3> Jv_inv = Jv.transpose() * (JvJvT + lambda_v * lambda_v * I3).inverse();

    Eigen::Matrix<double,6,1> qdot_v = Jv_inv * twist_base.head<3>();

    // Null-space projector for linear task
    Eigen::Matrix<double,6,6> I6 = Eigen::Matrix<double,6,6>::Identity();
    Eigen::Matrix<double,6,6> Nv = I6 - Jv_inv * Jv;

    // Secondary: angular velocity in null space
    Eigen::Matrix<double,3,6> Jw_N = Jw * Nv;
    Eigen::Matrix<double,3,3> JwNJwNT = Jw_N * Jw_N.transpose();
    Eigen::Matrix<double,6,3> JwN_inv = Jw_N.transpose() * (JwNJwNT + lambda_w * lambda_w * I3).inverse();

    Eigen::Vector3d w_residual = twist_base.tail<3>() - Jw * qdot_v;
    Eigen::Matrix<double,6,1> qdot_w = JwN_inv * w_residual;

    qdot_out = qdot_v + alpha_cancel * qdot_w;
}
