#pragma once

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

using Eigen::Vector4f;
using Eigen::Vector3f;
using Eigen::Vector2f;
using Line3f = Eigen::ParametrizedLine<float, 3>;
using Transform3f = Eigen::Transform<float, 3, Eigen::TransformTraits::Affine>;
