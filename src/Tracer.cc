#include "Tracer.hh"
#include "Scene.hh"
#include "Geometry.hh"
#include "Material.hh"

#include <cmath>

namespace bcr
{

ColorRGB Tracer::trace_ray(const Ray3& ray) const
{
    return ColorRGB::white();
}

ColorRGB Tracer::compute_brdf(
        const Vec3& view_vector,
        const Vec3& light_vector,
        const Vec3& normal_vector,
        const Material& mat) const
{
    Tracer::BrdfParameters params;

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

    auto diffuse = this->calculate_diffuse(params, mat);
    auto specular = this->calculate_specular(params, mat);
    
    return diffuse + specular;
}

ColorRGB Tracer::calculate_albedo_tint(const ColorRGB& color) const
{
    // CIELAB conversions and removal of lightness
    double luminance = ColorRGB {0.3, 0.6, 1.0}.dot(color);
    return (luminance > 0.0) ? color / luminance : ColorRGB::white();
}

ColorRGB Tracer::calculate_diffuse(const Tracer::BrdfParameters& params, const Material& mat) const
{
    auto fresnel = 0.5 + 2 * params.cos_theta_d * params.cos_theta_d * mat.roughness;
    return (mat.albedo / M_PI) 
        * (1 + (fresnel - 1) * pow(1 - params.cos_theta_light, 5)) 
        * (1 + (fresnel - 1) * pow(1 - params.cos_theta_view, 5));
}

} /* bcr */ 
