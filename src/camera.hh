#pragma once
#include "eigen.hh"

class Camera
{
public:
    Vector2f world_to_screen(const Vector3f&) const;
    Line3f cast_ray_through_pixel(const Vector3f&) const;
};
