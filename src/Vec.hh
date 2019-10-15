#ifndef VEC3_H
#define VEC3_H
#include <iostream>

namespace bcr
{

struct Vec3
{
    double x, y ,z;

    Vec3(double x, double y, double z) : x(x), y(y), z(z) {};

    // Get the length of the vector
    double get_magnitude()  const;

    // Get the length squared of the vector
    double get_magnitude2()  const;

    // Get the normalized vector (unit length)
    Vec3 get_normalized() const;

    // Dot product
    double dot(const Vec3&) const;

    // Cross product
    Vec3 cross(const Vec3&) const;

    Vec3 operator+ (const Vec3&) const;
    Vec3 operator- (const Vec3&) const;

    Vec3 operator* (double) const;
    Vec3 operator/ (double) const;

    Vec3 operator- () const;

    // Mutable

    // Shrink the vector to unit length
    Vec3& normalize();

    Vec3& operator+= (const Vec3&);
    Vec3& operator-= (const Vec3&);
    Vec3& operator*= (double);

    // Streaming
    friend std::ostream& operator<< (std::ostream& out, const Vec3& v); 
};

struct Vec2
{
    double x, y;

    Vec2(double x, double y) : x(x), y(y) {};

    // Get the length of the vector
    double get_magnitude()  const;

    // Get the length squared of the vector
    double get_magnitude2()  const;

    // Get the normalized vector (unit length)
    Vec2 get_normalized() const;

    // Dot product
    double dot(const Vec2&) const;

    // Cross product
    Vec3 cross(const Vec2&) const;

    Vec2 operator+ (const Vec2&) const;
    Vec2 operator- (const Vec2&) const;

    Vec2 operator* (double) const;
    Vec2 operator/ (double) const;

    Vec2 operator- () const;

    // Mutable

    // Shrink the vector to unit length
    Vec2& normalize();

    Vec2& operator+= (const Vec2&);
    Vec2& operator-= (const Vec2&);
    Vec2& operator*= (double);

    // Streaming
    friend std::ostream& operator<< (std::ostream& out, const Vec2& v); 
};
    
} /* bcr */ 

#endif /* VEC3_H */
