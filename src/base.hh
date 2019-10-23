#pragma once
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

using v4 = Eigen::Vector4d;
using v3 = Eigen::Vector3d;
using v2 = Eigen::Vector2d;

using Mat3 = Eigen::Matrix3d;
using Mat2 = Eigen::Matrix2d;

using Ray3 = Eigen::ParametrizedLine<double, 3>;
using Ray2 = Eigen::ParametrizedLine<double, 2>;

using Transform = Eigen::Transform<double, 3, Eigen::Projective>;

using Quaternion = Eigen::Quaternion<double>;
