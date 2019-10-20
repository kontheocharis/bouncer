#include "Camera.hh"
#include "Geometry.hh"
#include <cmath>
#include <iostream>

namespace bcr
{

Camera::Camera(const CameraSettings settings) : Object(settings.transform)
{
    this->set_settings(settings);
}

void Camera::set_settings(const CameraSettings settings)
{
    m_focal_length = settings.focal_length;
    m_field_of_view = M_PI * settings.field_of_view / 180;
    m_pixel_width = settings.pixel_width;
    m_pixel_height = settings.pixel_height;
    m_view_matrix = settings.transform.inverse();
    Object(settings.transform);

    m_forward = m_transform.linear().col(0);
    m_right = m_transform.linear().col(1);
    m_up = m_transform.linear().col(2);

    m_translation = m_transform.translation();

    m_half_screen_width = m_focal_length * tan(m_field_of_view / 2);
    m_half_screen_height = m_half_screen_width * m_pixel_height / m_pixel_width;

    m_single_pixel_half_width = m_half_screen_width / m_pixel_width;
}

void Camera::reset_transform() 
{
    reset_transform();
    m_view_matrix = m_transform.inverse(); 
}


void Camera::apply_transform(const Transform& t) 
{
    apply_transform(t);
    m_view_matrix = m_transform.inverse();
}


Ray3 Camera::cast_ray_through_pixel(int x, int y) const
{
    const Vec3 dir = m_translation
        + m_forward * m_focal_length
        + m_right * ( m_half_screen_width * (m_pixel_width - 2 * x) / m_pixel_width - m_single_pixel_half_width )
        + m_up * (m_half_screen_height * (m_pixel_height - 2 * y) / m_pixel_height - m_single_pixel_half_width );

    return Ray3 { m_translation, dir.normalized() };
}


}
