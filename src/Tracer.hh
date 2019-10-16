#ifndef TRACER_H
#define TRACER_H

#include "Scene.hh"
#include "Geometry.hh"
#include "Camera.hh"
#include "Material.hh"

#include <vector>

namespace bcr
{

class Tracer
{
public:
    Tracer(const Scene& scene, const Camera& camera) : m_scene(scene), m_camera(camera) {};

    std::vector<ColorRGB> capture() const;

private:
    const Scene& m_scene;
    const Camera& m_camera;

    ColorRGB trace_ray(const Ray3&) const;
    ColorRGB calculate_albedo_tint(const ColorRGB& color) const;
    ColorRGB calculate_sheen() const;
};

} /* bcr */

#endif /* TRACER_H */
