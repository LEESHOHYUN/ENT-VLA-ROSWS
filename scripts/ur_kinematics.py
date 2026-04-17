"""
UR5e Kinematics — Python port of ur_kinematics.cpp

FK, IK (8 configurations), Jacobian, DLS, manipulability, velocity servo.
Pure numpy — no ROS dependencies.
"""

import numpy as np
from numpy import sin, cos, sqrt, arctan2, arccos, pi
from numpy.linalg import norm, det, inv


class URKinematics:
    """UR5e forward/inverse kinematics and Jacobian utilities."""

    def __init__(self, d1=0.1626908436, a2=-0.4250156423, a3=-0.3921146227,
                 d4=0.1335368450, d5=0.0995866193, d6=0.0994997837):
        self.d1 = d1
        self.a2 = a2
        self.a3 = a3
        self.d4 = d4
        self.d5 = d5
        self.d6 = d6
        self.T_flange_tcp = np.eye(4)

    # ================================================================
    # Tool TCP
    # ================================================================
    def set_tool_tcp(self, t_tcp, rvec_tcp):
        """Set tool center point offset (translation + axis-angle)."""
        t_tcp = np.asarray(t_tcp, dtype=float)
        rvec_tcp = np.asarray(rvec_tcp, dtype=float)
        self.T_flange_tcp = np.eye(4)
        self.T_flange_tcp[:3, :3] = rvec_to_R(rvec_tcp)
        self.T_flange_tcp[:3, 3] = t_tcp

    # ================================================================
    # Forward Kinematics
    # ================================================================
    def forward_kinematics(self, q):
        """FK: joint angles (6,) -> 4x4 homogeneous transform (base->flange)."""
        q = np.asarray(q, dtype=float)
        q1, q2, q3, q4, q5, q6 = q

        s1, c1 = sin(q1), cos(q1)
        s2, c2 = sin(q2), cos(q2)
        s3, c3 = sin(q3), cos(q3)
        s4, c4 = sin(q4), cos(q4)
        s5, c5 = sin(q5), cos(q5)
        s6, c6 = sin(q6), cos(q6)
        s23, c23 = sin(q2 + q3), cos(q2 + q3)

        d1, a2, a3, d4, d5, d6 = self.d1, self.a2, self.a3, self.d4, self.d5, self.d6

        px = d6*(c1*c23*c4*s5 + c1*s23*c5 + s1*s4*s5) + d5*c1*s23 + d4*s1 + a3*c1*c23 + a2*c1*c2
        py = d6*(s1*c23*c4*s5 + s1*s23*c5 - c1*s4*s5) + d5*s1*s23 - d4*c1 + a3*s1*c23 + a2*s1*c2
        pz = d6*(-s23*c4*s5 + c23*c5) + d5*c23 + d1 + a3*(-s23) + a2*(-s2)

        R = np.zeros((3, 3))
        R[0, 0] = c6*(c1*c23*c4*c5 + c1*s23*(-s5) + s1*s4*c5) - s6*(c1*c23*(-s4) + s1*c4)
        R[0, 1] = -s6*(c1*c23*c4*c5 + c1*s23*(-s5) + s1*s4*c5) - c6*(c1*c23*(-s4) + s1*c4)
        R[0, 2] = c1*c23*c4*s5 + c1*s23*c5 + s1*s4*s5
        R[1, 0] = c6*(s1*c23*c4*c5 + s1*s23*(-s5) - c1*s4*c5) - s6*(s1*c23*(-s4) - c1*c4)
        R[1, 1] = -s6*(s1*c23*c4*c5 + s1*s23*(-s5) - c1*s4*c5) - c6*(s1*c23*(-s4) - c1*c4)
        R[1, 2] = s1*c23*c4*s5 + s1*s23*c5 - c1*s4*s5
        R[2, 0] = c6*(-s23*c4*c5 + c23*(-s5)) - s6*(s23*s4)
        R[2, 1] = -s6*(-s23*c4*c5 + c23*(-s5)) - c6*(s23*s4)
        R[2, 2] = -s23*c4*s5 + c23*c5

        T = np.eye(4)
        T[:3, :3] = R
        T[:3, 3] = [px, py, pz]
        return T

    def forward_kinematics_tcp(self, q):
        """FK to TCP (with tool offset)."""
        return self.forward_kinematics(q) @ self.T_flange_tcp

    # ================================================================
    # Geometric Jacobian (numerical)
    # ================================================================
    def jacobian_tcp(self, q):
        """6x6 geometric Jacobian at TCP via finite differences."""
        q = np.asarray(q, dtype=float)
        dq = 1e-8
        J = np.zeros((6, 6))

        T0 = self.forward_kinematics_tcp(q)
        p0 = T0[:3, 3]
        R0 = T0[:3, :3]

        for i in range(6):
            q_plus = q.copy()
            q_plus[i] += dq
            T_plus = self.forward_kinematics_tcp(q_plus)

            J[:3, i] = (T_plus[:3, 3] - p0) / dq

            dR = T_plus[:3, :3] @ R0.T
            domega = R_to_rvec(dR) / dq
            J[3:, i] = domega

        return J

    # ================================================================
    # DLS inverse, manipulability
    # ================================================================
    @staticmethod
    def dls_inverse(J, lam):
        """Damped Least Squares: J^T (J J^T + lam^2 I)^{-1}"""
        JJT = J @ J.T
        return J.T @ inv(JJT + lam**2 * np.eye(6))

    @staticmethod
    def manipulability(J):
        """sqrt(det(J J^T))"""
        return sqrt(max(0.0, det(J @ J.T)))

    # ================================================================
    # Velocity servo step
    # ================================================================
    def velocity_servo_step(self, q, T_des, Kp, Ko, lam, dt, qdot_limit):
        """
        One step of velocity servo towards target pose.
        Returns (q_next, qdot, stats_dict).
        """
        q = np.asarray(q, dtype=float)
        T_cur = self.forward_kinematics_tcp(q)

        ep = T_des[:3, 3] - T_cur[:3, 3]
        Re = T_des[:3, :3] @ T_cur[:3, :3].T
        eo = R_to_rvec(Re)

        twist = np.concatenate([Kp * ep, Ko * eo])

        J = self.jacobian_tcp(q)
        J_inv = self.dls_inverse(J, lam)
        qdot = J_inv @ twist

        max_qd = np.abs(qdot).max()
        if max_qd > qdot_limit and max_qd > 1e-10:
            qdot *= qdot_limit / max_qd

        q_next = q + qdot * dt
        stats = {"pos_err": norm(ep), "ori_err": norm(eo),
                 "manip": self.manipulability(J)}
        return q_next, qdot, stats

    # ================================================================
    # Inverse Kinematics (8 configs)
    # ================================================================
    def inverse_kinematics_8(self, T06, q_current=None):
        """
        Solve IK for all 8 shoulder/elbow/wrist configurations.
        Returns (sols[8x6], valid[8]).
        """
        configs = [
            (1, 1, 1), (1, 1, -1), (1, -1, 1), (1, -1, -1),
            (-1, 1, 1), (-1, 1, -1), (-1, -1, 1), (-1, -1, -1),
        ]
        sols = np.zeros((8, 6))
        valid = np.zeros(8, dtype=bool)

        for i, (sh, el, wr) in enumerate(configs):
            ok, q_sol = self._solve_ik_config(T06, sh, el, wr)
            if ok:
                sols[i] = q_sol
                valid[i] = True

        return sols, valid

    def pick_best_from_8(self, T_target, sols, valid, q_current):
        """Pick the IK solution closest to q_current (weighted joint distance)."""
        q_current = np.asarray(q_current, dtype=float)
        best_score = float('inf')
        best_idx = -1
        q_best = np.zeros(6)
        weights = np.array([1.0, 1.0, 1.0, 1.0, 1.0, 0.5])

        for i in range(8):
            if not valid[i]:
                continue
            adjusted = self._adjust_and_wrap(sols[i], q_current)
            diff = adjusted - q_current
            diff = np.mod(diff + pi, 2 * pi) - pi  # wrap to [-pi, pi]
            score = np.sum(weights * diff**2)
            if score < best_score:
                best_score = score
                q_best = adjusted
                best_idx = i

        return q_best, best_idx

    def tcp_target_to_flange_target(self, T_tcp):
        """Convert TCP target to flange target (remove tool offset)."""
        return T_tcp @ _fast_inverse(self.T_flange_tcp)

    def ik_best_for_tcp_pose(self, T_tcp, q_current):
        """
        Full customMoveL IK pipeline:
        TCP target -> flange target -> IK8 -> pick best.
        Returns (success, q_best, best_idx).
        """
        T_flange = self.tcp_target_to_flange_target(T_tcp)
        sols, valid = self.inverse_kinematics_8(T_flange, q_current)

        if not np.any(valid):
            return False, np.zeros(6), -1

        q_best, best_idx = self.pick_best_from_8(T_flange, sols, valid, q_current)
        if best_idx < 0:
            return False, np.zeros(6), -1

        return True, q_best, best_idx

    # ================================================================
    # Private: single config IK solver
    # ================================================================
    def _solve_ik_config(self, T06, shoulder_sign, elbow_sign, wrist_sign):
        d1, a2, a3, d4, d5, d6 = self.d1, self.a2, self.a3, self.d4, self.d5, self.d6
        th = np.zeros(6)

        p05 = T06[:3, 3] - d6 * T06[:3, :3][:, 2]

        # Joint 1
        psi = arctan2(p05[1], p05[0])
        r_sq = p05[0]**2 + p05[1]**2
        if r_sq < d4**2:
            return False, th
        phi = arccos(np.clip(d4 / sqrt(r_sq), -1.0, 1.0))

        if shoulder_sign >= 0:
            th[0] = psi + phi + pi / 2
        else:
            th[0] = psi - phi + pi / 2

        # Joint 5
        s1, c1 = sin(th[0]), cos(th[0])
        q5_arg = (p05[0] * s1 - p05[1] * c1 - d4) / d6
        if abs(q5_arg) > 1.0 + 1e-8:
            return False, th
        q5_arg = np.clip(q5_arg, -1.0, 1.0)

        if wrist_sign >= 0:
            th[4] = arccos(q5_arg)
        else:
            th[4] = -arccos(q5_arg)

        # Joint 6
        s5 = sin(th[4])
        if abs(s5) < 1e-10:
            th[5] = 0.0
        else:
            Xhat = T06[:3, :3][:, 0]
            Yhat = T06[:3, :3][:, 1]
            num = (-Xhat[0] * s1 + Xhat[1] * c1)
            denom = (Yhat[0] * s1 - Yhat[1] * c1)
            th[5] = arctan2(num / s5, denom / s5)

        # Joints 2, 3, 4
        c6, s6 = cos(th[5]), sin(th[5])
        T01 = _Rz_Tz(th[0], d1)

        c5v, s5v = cos(th[4]), sin(th[4])
        T45 = np.eye(4)
        T45[0, 0] = c5v; T45[0, 2] = s5v
        T45[2, 0] = -s5v; T45[2, 2] = c5v
        T45[2, 3] = d5

        T56 = np.eye(4)
        T56[0, 0] = c6; T56[0, 1] = -s6
        T56[1, 0] = s6; T56[1, 1] = c6
        T56[2, 3] = d6

        T14 = _fast_inverse(T01) @ T06 @ _fast_inverse(T45 @ T56)

        p14x = T14[0, 3]
        p14z = T14[2, 3]

        c3_arg = (p14x**2 + p14z**2 - a2**2 - a3**2) / (2.0 * a2 * a3)
        if abs(c3_arg) > 1.0 + 1e-8:
            return False, th
        c3_arg = np.clip(c3_arg, -1.0, 1.0)

        if elbow_sign >= 0:
            th[2] = arccos(c3_arg)
        else:
            th[2] = -arccos(c3_arg)

        s3, c3 = sin(th[2]), cos(th[2])
        th[1] = arctan2(-p14z, -p14x) - arctan2(a3 * s3, a2 + a3 * c3)

        # Joint 4
        c2, s2v = cos(th[1]), sin(th[1])
        T12 = np.eye(4)
        T12[0, 0] = c2; T12[0, 1] = -s2v; T12[0, 3] = a2 * c2
        T12[1, 0] = s2v; T12[1, 1] = c2; T12[1, 3] = a2 * s2v

        T23 = np.eye(4)
        T23[0, 0] = c3; T23[0, 1] = -s3; T23[0, 3] = a3 * c3
        T23[1, 0] = s3; T23[1, 1] = c3; T23[1, 3] = a3 * s3

        T34 = _fast_inverse(T12 @ T23) @ T14
        th[3] = arctan2(T34[1, 0], T34[0, 0])

        return True, th

    def _adjust_and_wrap(self, q, q_current):
        result = np.copy(q)
        for i in range(6):
            result[i] = np.mod(result[i], 2 * pi)
            if result[i] > pi:
                result[i] -= 2 * pi
            # Adjust to closest equivalent
            diff = result[i] - q_current[i]
            diff = np.mod(diff + pi, 2 * pi) - pi
            result[i] = q_current[i] + diff
        return result


# ====================================================================
# Module-level helpers (match C++ free functions)
# ====================================================================

def rvec_to_R(rvec):
    """Axis-angle vector -> 3x3 rotation matrix (Rodrigues)."""
    rvec = np.asarray(rvec, dtype=float)
    theta = norm(rvec)
    if theta < 1e-12:
        return np.eye(3)
    k = rvec / theta
    K = np.array([[0, -k[2], k[1]],
                  [k[2], 0, -k[0]],
                  [-k[1], k[0], 0]])
    return np.eye(3) + sin(theta) * K + (1 - cos(theta)) * K @ K


def R_to_rvec(R):
    """3x3 rotation matrix -> axis-angle vector."""
    theta = arccos(np.clip((np.trace(R) - 1) / 2, -1.0, 1.0))
    if theta < 1e-12:
        return np.zeros(3)
    r = np.array([R[2, 1] - R[1, 2],
                  R[0, 2] - R[2, 0],
                  R[1, 0] - R[0, 1]]) / (2 * sin(theta))
    return r * theta


def pose_to_T(pose_6):
    """[x y z rx ry rz] -> 4x4 homogeneous transform."""
    pose_6 = np.asarray(pose_6, dtype=float)
    T = np.eye(4)
    T[:3, :3] = rvec_to_R(pose_6[3:6])
    T[:3, 3] = pose_6[0:3]
    return T


def T_to_pose(T):
    """4x4 -> [x y z rx ry rz]."""
    p = T[:3, 3]
    rvec = R_to_rvec(T[:3, :3])
    return np.concatenate([p, rvec])


def _Rz_Tz(theta, dz):
    T = np.eye(4)
    c, s = cos(theta), sin(theta)
    T[0, 0] = c; T[0, 1] = -s
    T[1, 0] = s; T[1, 1] = c
    T[2, 3] = dz
    return T


def _fast_inverse(T):
    T_inv = np.eye(4)
    T_inv[:3, :3] = T[:3, :3].T
    T_inv[:3, 3] = -T[:3, :3].T @ T[:3, 3]
    return T_inv
