#ifndef CAMERA_H
#define CAMERA_H

#include "Geometry.hh"
#include "Object.hh"
#include "Material.hh"

#include <cmath>

namespace bcr
{

struct CameraSettings
{
    double pixel_width;
    double pixel_height;

    Transform transform = Transform::Identity();
    double focal_length = 1.0;
    double field_of_view = 60;
};

class Camera : public Object
{
public:

    Camera(const CameraSettings settings);

    void reset_transform();
    void apply_transform(const Transform&);
    void set_settings(const CameraSettings);

private:
    Vec3 m_position;
    Transform m_view_matrix;

    Vec3 m_forward;
    Vec3 m_right;
    Vec3 m_up;
    Vec3 m_translation;

    double m_half_screen_width;
    double m_half_screen_height;
    double m_single_pixel_half_width;

    double m_focal_length;
    double m_field_of_view;

    int m_pixel_width, m_pixel_height;

    Ray3 cast_ray_through_pixel(int x, int y) const;
};

} /* bcr */ 

#endif /* CAMERA_H */
