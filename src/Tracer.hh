#ifndef TRACER_H
#define TRACER_H

#include "Scene.hh"
#include "Geometry.hh"
#include "Camera.hh"
#include "Material.hh"

#include <vector>
#include <memory>

namespace bcr
{

// Implements Disney's Principled BRDF
class Tracer
{
public:
    Tracer(const Scene* scene, const Camera* camera)
        : m_camera(std::shared_ptr<const Camera>(camera)), m_scene(std::shared_ptr<const Scene>(scene)) {  };

    std::vector<ColorRGB> trace() const;
private:

    struct BrdfParameters
    {
        Vec3 view_vector;
        Vec3 light_vector;

        Vec3 half_vector;
        Vec3 normal_vector;

        double cos_theta_view; // Angle of incidence of view vector
        double cos_theta_light; // Angle of incidence of light vector
        double cos_theta_h; // Angle between normal vector and half-vector
        double cos_theta_d; // Angle between light vector (or view vector) and half-vector
    };

    std::weak_ptr<const Scene> m_scene;
    std::weak_ptr<const Camera> m_camera;

    ColorRGB trace_ray(const Ray3&) const;

    ColorRGB calculate_diffuse(const BrdfParameters&, const Material&) const;

    ColorRGB calculate_specular(const BrdfParameters&, const Material&) const;

    ColorRGB calculate_sheen(const BrdfParameters&) const;

    ColorRGB calculate_albedo_tint(const ColorRGB& color) const;

    ColorRGB compute_brdf(
            const Vec3& view_vector,
            const Vec3& light_vector,
            const Vec3& normal_vector,
            const Material& material) const;

};

} /* bcr */

#endif /* TRACER_H */
