#ifndef VEC3_H
#define VEC3_H
#include <iostream>

namespace bcr
{

struct Vec3
{
    double x, y ,z;

    Vec3(double, double, double);

    // Pure
    double get_magnitude()  const;
    double get_magnitude2()  const;
    Vec3 get_normalized() const;

    double dot(const Vec3&) const;
    Vec3 cross(const Vec3&) const;

    Vec3 operator+ (const Vec3&) const;
    Vec3 operator- (const Vec3&) const;

    Vec3 operator* (double) const;
    Vec3 operator/ (double) const;

    Vec3 operator- () const;

    // Mutable
    Vec3& normalize();
    Vec3& operator+= (const Vec3&);
    Vec3& operator*= (double);

    // Destruct
    virtual ~Vec3();

    // Streaming
    friend std::ostream& operator<< (std::ostream& out, const Vec3& v); 
};
    
} /* bcr */ 

#endif /* VEC3_H */
