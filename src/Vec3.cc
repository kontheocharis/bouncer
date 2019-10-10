#include "Vec3.hh"
#include <cmath>

namespace bcr
{

Vec3::Vec3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vec3::get_magnitude() const
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

double Vec3::get_magnitude2() const
{
    return (this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec3 Vec3::get_normalized() const
{
    return (*this) / this->get_magnitude();
}

double Vec3::dot (const Vec3& v) const
{
    return (this->x * v.x + this->y * v.y + this->z * v.z);
}

Vec3 Vec3::cross (const Vec3& v) const
{
    return Vec3(
            this->y * v.z - this->z * v.y,
            this->z * v.x - this->x * v.z,
            this->x * v.y - this->y * v.x
            );
}

Vec3 Vec3::operator+ (const Vec3& v) const
{
    return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vec3 Vec3::operator- (const Vec3& v) const
{
    return Vec3(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vec3 Vec3::operator* (double a) const
{
    return Vec3(this->x * a, this->y * a, this->z * a);
}

Vec3 Vec3::operator/ (double a) const
{
    return Vec3(this->x / a, this->y / a, this->z / a);
}

Vec3 Vec3::operator- () const
{
    return Vec3(-this->x, -this->y, -this->z);
}

Vec3& Vec3::normalize()
{
    auto mag = this->get_magnitude();
    this->x /= mag;
    this->y /= mag;
    this->z /= mag;
    
    return *this;
}

Vec3& Vec3::operator+= (const Vec3& v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;

    return *this;
}

Vec3& Vec3::operator*= (double a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;

    return *this;
}

} /* bcr */
