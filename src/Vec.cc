#include "Vec.hh"
#include <cmath>
#include <iostream>

namespace bcr
{

// Magnitudes and normalized
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

double Vec2::get_magnitude() const
{
    return sqrt(this->x * this->x + this->y * this->y);
}

double Vec2::get_magnitude2() const
{
    return (this->x * this->x + this->y * this->y);
}

Vec2 Vec2::get_normalized() const
{
    return (*this) / this->get_magnitude();
}


// Dots and crosses

double Vec3::dot (const Vec3& v) const
{
    return (this->x * v.x + this->y * v.y + this->z * v.z);
}

double Vec2::dot (const Vec2& v) const
{
    return (this->x * v.x + this->y * v.y);
}

Vec3 Vec3::cross (const Vec3& v) const
{
    return Vec3 {
            this->y * v.z - this->z * v.y,
            this->z * v.x - this->x * v.z,
            this->x * v.y - this->y * v.x
            };
}

Vec3 Vec2::cross (const Vec2& v) const
{
    return Vec3 {0, 0, this->x * v.y - this->y * v.x};
}


// Operators
// 3

Vec3 Vec3::operator+ (const Vec3& v) const
{
    return Vec3 {this->x + v.x, this->y + v.y, this->z + v.z};
}

Vec3 Vec3::operator- (const Vec3& v) const
{
    return Vec3{this->x - v.x, this->y - v.y, this->z - v.z};
}

Vec3 Vec3::operator* (double a) const
{
    return Vec3{this->x * a, this->y * a, this->z * a};
}

Vec3 Vec3::operator/ (double a) const
{
    return Vec3{this->x / a, this->y / a, this->z / a};
}

Vec3 Vec3::operator- () const
{
    return Vec3{-this->x, -this->y, -this->z};
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

Vec3& Vec3::operator-= (const Vec3& v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;

    return *this;
}

Vec3& Vec3::operator*= (double a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;

    return *this;
}

std::ostream& operator<< (std::ostream& out, const Vec3& v)
{
    out << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return out;
}

// 2

Vec2 Vec2::operator+ (const Vec2& v) const
{
    return Vec2{this->x + v.x, this->y + v.y};
}

Vec2 Vec2::operator- (const Vec2& v) const
{
    return Vec2{this->x - v.x, this->y - v.y};
}

Vec2 Vec2::operator* (double a) const
{
    return Vec2{this->x * a, this->y * a};
}

Vec2 Vec2::operator/ (double a) const
{
    return Vec2{this->x / a, this->y / a};
}

Vec2 Vec2::operator- () const
{
    return Vec2{-this->x, -this->y};
}

Vec2& Vec2::normalize()
{
    auto mag = this->get_magnitude();
    this->x /= mag;
    this->y /= mag;
    
    return *this;
}

Vec2& Vec2::operator+= (const Vec2& v)
{
    this->x += v.x;
    this->y += v.y;

    return *this;
}

Vec2& Vec2::operator-= (const Vec2& v)
{
    this->x -= v.x;
    this->y -= v.y;

    return *this;
}

Vec2& Vec2::operator*= (double a)
{
    this->x *= a;
    this->y *= a;

    return *this;
}

std::ostream& operator<< (std::ostream& out, const Vec2& v)
{
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

} /* bcr */
