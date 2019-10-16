#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

namespace bcr
{

using Vec3 = Eigen::Vector3d;
using Vec2 = Eigen::Vector2d;

using Matrix3 = Eigen::Matrix3d;
using Matrix2 = Eigen::Matrix2d;

using Ray3 = Eigen::ParametrizedLine<double, 3>;
using Ray2 = Eigen::ParametrizedLine<double, 2>;

using Transform = Eigen::Transform<double, 3, Eigen::Projective>;

using Quaternion = Eigen::Quaternion<double>;

}

#endif /* GEOMETRY_H */
