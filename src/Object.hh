#ifndef OBJECT_H
#define OBJECT_H

#include "Geometry.hh"

namespace bcr
{

class Object
{
public:
    Object(Transform t) : m_transform(t) {  };

    Transform get_transform() { return m_transform; }
    void reset_transform() { m_transform = Transform::Identity(); };
    void apply_transform(const Transform& t) { m_transform = m_transform * t; };

protected:
    Transform m_transform;
};

}

#endif /* OBJECT_H */
