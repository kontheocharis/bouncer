#ifndef RAY_H
#define RAY_H
#include "Vec.hh"

namespace bcr
{

struct Ray
{
    Vec3 position, direction;
    Ray(Vec3 position, Vec3 direction) : position(position), direction(direction) {};
};

} /* bcr */ 

#endif /* RAY_H */
