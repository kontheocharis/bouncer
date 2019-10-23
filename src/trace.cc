#include "trace.hh"
#include "camera.hh"
#include "base.hh"
#include "scene.hh"
#include "material.hh"

#include <cmath>
#include <iostream>

struct CameraComputed : Camera
{
    v3 forward;
    v3 right;
    v3 up;
    v3 position;

    double half_screen_width;
    double half_screen_height;

    double single_pixel_half_width;

    CameraComputed(const Camera& camera) : 
        Camera(camera),
        forward(camera.view_matrix.linear().col(0)),
        right(camera.view_matrix.linear().col(1)),
        up(camera.view_matrix.linear().col(2)),
        position(camera.view_matrix.translation())
    {
        half_screen_width = camera.focal_length * tan(camera.field_of_view / 2);
        half_screen_height = half_screen_width * camera.pixel_height / camera.pixel_width;
        single_pixel_half_width = half_screen_width / camera.pixel_width;
    }
};

struct DisneyBrdfParameters
{
    v3 view_vector;
    v3 light_vector;

    v3 half_vector;
    v3 normal_vector;

    double cos_theta_view; // Angle of incidence of view vector
    double cos_theta_light; // Angle of incidence of light vector
    double cos_theta_h; // Angle between normal vector and half-vector
    double cos_theta_d; // Angle between light vector (or view vector) and half-vector
};

Ray3 cast_ray_through_camera_pixel(const CameraComputed& c, int x, int y)
{
    const v3 dir = c.position
        + c.forward * c.focal_length
        + c.right * (c.half_screen_width * (c.pixel_width - 2 * x) / c.pixel_width - c.single_pixel_half_width )
        + c.up * (c.half_screen_height * (c.pixel_height - 2 * y) / c.pixel_height - c.single_pixel_half_width );

    return Ray3 { c.position, dir.normalized() };
}

//
// Disney
//

std::vector<v4> trace_disney(const Scene& scene, const Camera& cam, const DisneyOptions& opts)
{
    return { v4::Zero() };
    CameraComputed c(cam);
}


v4 d_trace_ray(const Ray3& ray)
{
    return v4::Ones();
}

v4 d_calculate_diffuse(const DisneyBrdfParameters& params, const DisneyMaterial& mat)
{
    auto fresnel = 0.5 + 2 * params.cos_theta_d * params.cos_theta_d * mat.roughness;
    return (mat.albedo / M_PI) 
        * (1 + (fresnel - 1) * pow(1 - params.cos_theta_light, 5)) 
        * (1 + (fresnel - 1) * pow(1 - params.cos_theta_view, 5));
}

v4 d_calculate_specular(const DisneyBrdfParameters&, const DisneyMaterial&)
{
    return v4::Ones();
}

v4 d_compute_brdf(
        const v3& view_vector,
        const v3& light_vector,
        const v3& normal_vector,
        const DisneyMaterial& mat)
{
    DisneyBrdfParameters params;

    params.view_vector = view_vector;
    params.light_vector = light_vector;
    params.half_vector = (view_vector + light_vector).normalized();
    params.normal_vector = normal_vector;

    params.cos_theta_view = 
        view_vector.dot(normal_vector) / (view_vector.norm() * normal_vector.norm());

    params.cos_theta_light = 
        light_vector.dot(normal_vector) / (light_vector.norm() * normal_vector.norm());

    params.cos_theta_h = 
        normal_vector.dot(params.half_vector) / (normal_vector.norm() * params.half_vector.norm());

    params.cos_theta_d = 
        view_vector.dot(params.half_vector) / (view_vector.norm() * params.half_vector.norm());

    auto diffuse = d_calculate_diffuse(params, mat);
    auto specular = d_calculate_specular(params, mat);
    
    return diffuse + specular;
}

v4 d_calculate_albedo_tint(const v4& color)
{
    // CIELAB conversions and removal of lightness
    double luminance = v4{0.3, 0.6, 1.0, 0.0}.dot(color);
    if (luminance > 0.0) 
        return color / luminance;
    return v4::Ones();
}
