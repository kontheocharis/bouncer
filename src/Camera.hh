#ifndef CAMERA_H
#define CAMERA_H

#include "Vec.hh"
#include "Ray.hh"
#include "Matrix.hh"
#include "Transform.hh"

namespace bcr
{
    
class Camera
{
public:
    Ray cast_ray_through_pixel(int x, int y) const;

private:
    Transform m_transform;

    double m_focal_length;
    double m_field_of_view;

    int pixel_width, pixel_height;
};

} /* bcr */ 

#endif /* CAMERA_H */
