#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Vec.hh"

namespace bcr
{

struct Transform
{
public:
    Vec3 m_position,
         m_orientation,  // In Tait-Bryan angles
         m_pivot,
         m_scale;

public:
};

}

#endif /* TRANSFORM_H */
