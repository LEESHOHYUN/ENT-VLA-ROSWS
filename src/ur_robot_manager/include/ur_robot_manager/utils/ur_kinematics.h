// ur_kinematics.h - Exact port from original ur_kinematics.hpp
// Pure math - NO ROS dependencies. Uses Eigen throughout.
#pragma once
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <array>
#include <string>

struct PoseAA {
  Eigen::Vector3d p;    // [x y z] (m), Base frame
  Eigen::Vector3d rvec; // Angle-Axis (rad) : axis * angle
};

struct JointLimits {
  double min, max;
};

class URKinematics {
public:
  URKinematics();

  // --- Tool / TCP offset ---
  void setToolTCP(const Eigen::Vector3d& t_tcp, const Eigen::Vector3d& rvec_tcp);
  const Eigen::Matrix4d& T_flange_tcp() const { return T_flange_tcp_; }

  // --- Angle-Axis <-> R ---
  static Eigen::Matrix3d rodrigues(const Eigen::Vector3d& axis, double ang);
  static Eigen::Matrix3d rvecToR(const Eigen::Vector3d& rvec);
  static Eigen::Vector3d RToRvec(const Eigen::Matrix3d& R);
  static Eigen::Vector3d unwrapRvec(const Eigen::Vector3d& rvec_prev,
                                    const Eigen::Vector3d& rvec_now);

  // --- Pose <-> Transform ---
  static Eigen::Matrix4d poseToT(const PoseAA& pose);
  static PoseAA TToPose(const Eigen::Matrix4d& T);

  // --- Forward Kinematics ---
  Eigen::Matrix4d forwardKinematics(const Eigen::Matrix<double,6,1>& q,
                                    std::vector<Eigen::Matrix4d>* Tlist=nullptr) const;
  Eigen::Matrix4d forwardKinematicsTCP(const Eigen::Matrix<double,6,1>& q,
                                       std::vector<Eigen::Matrix4d>* Tlist=nullptr) const;

  // --- Geometric Jacobian (Base frame, TCP) ---
  Eigen::Matrix<double,6,6> geometricJacobianTCP(const Eigen::Matrix<double,6,1>& q) const;

  // --- Damped Least Squares inverse ---
  static Eigen::Matrix<double,6,6> dlsInverse(const Eigen::Matrix<double,6,6>& J, double lambda);

  // --- Velocity servo step ---
  struct ServoStats { double pos_err; double ori_err; double manip; };
  void velocityServoStep(const Eigen::Matrix<double,6,1>& q,
                         const Eigen::Matrix4d& T_des,
                         double Kp, double Ko, double lam, double dt,
                         double qdot_limit,
                         const std::string& nullspace_mode,
                         Eigen::Matrix<double,6,1>& q_next,
                         Eigen::Matrix<double,6,1>& qdot,
                         ServoStats* out=nullptr) const;

  // --- Inverse Kinematics (8 configurations) ---
  void inverseKinematics8(
      const Eigen::Matrix4d& T06,
      const Eigen::Matrix<double,6,1>* q_current,
      std::array<Eigen::Matrix<double,6,1>,8>& sols,
      std::array<bool,8>& valid) const;

  std::pair<Eigen::Matrix<double,6,1>, int> pickBestFrom8(
                const Eigen::Matrix4d& T_target,
                const std::array<Eigen::Matrix<double,6,1>,8>& sols,
                const std::array<bool,8>& valid,
                const Eigen::Matrix<double,6,1>& q_current) const;

  static double manipulability(const Eigen::Matrix<double,6,6>& J);

  Eigen::Matrix4d tcpTargetToFlangeTarget(const Eigen::Matrix4d& T_tcp) const;

  bool ikBestForTCPPose(const Eigen::Matrix4d& T_tcp,
                        const Eigen::Matrix<double,6,1>& q_current,
                        Eigen::Matrix<double,6,1>& q_best,
                        int* best_index=nullptr) const;

  void solveTwistPrioritized(const Eigen::Matrix<double,6,1>& q,
                            const Eigen::Matrix<double,6,1>& twist_base,
                            double lambda_v, double lambda_w,
                            Eigen::Matrix<double,6,1>& qdot_out,
                            double alpha_cancel = 1.0) const;

  Eigen::Matrix4d getTflangeTcp() const { return T_flange_tcp_; }

  void setUR5eDHparams(double d1, double a2, double a3, double d4, double d5, double d6) {
    d1_ = d1; a2_ = a2; a3_ = a3; d4_ = d4; d5_ = d5; d6_ = d6;
  }

private:
  double d1_, a2_, a3_, d4_, d5_, d6_;
  Eigen::Matrix4d T_flange_tcp_;

  static Eigen::Matrix4d Rx(double a);
  static Eigen::Matrix4d RzTz(double th, double dz);

  bool solveIKConfig(const Eigen::Matrix4d& T06,
                     const Eigen::Matrix<double,6,1>* q_current,
                     int shoulder_sign, int elbow_sign, int wrist_sign,
                     Eigen::Matrix<double,6,1>& th_out) const;

  static double acos_biased(double x, int sign, double eps=1e-9);
  static Eigen::Matrix4d fastInverse(const Eigen::Matrix4d& T);
  static double wrap_to_2pi(double a);
  static double adjust_angle_to_closest(double a, double ref);

  Eigen::Matrix<double,6,1> adjust_and_wrap(
      const Eigen::Matrix<double,6,1>& q,
      const Eigen::Matrix<double,6,1>* q_current,
      bool do_adjust=true, bool do_wrap=true) const;

  double scoreSolution(const Eigen::Matrix<double,6,1>& q,
                       const Eigen::Matrix4d& T_target,
                       const Eigen::Matrix<double,6,1>& q_current) const;
};
