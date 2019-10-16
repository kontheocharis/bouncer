#include "Tracer.hh"
#include "Scene.hh"
#include "Geometry.hh"
#include "Material.hh"

namespace bcr
{

ColorRGB Tracer::trace_ray(const Ray3& ray) const
{
    auto sheen = this->calculate_sheen();
}

ColorRGB Tracer::calculate_albedo_tint(const ColorRGB& color) const
{
    // CIELAB conversions and removal of lightness
    double luminance = ColorRGB {0.3, 0.6, 1.0}.dot(color);
    return (luminance > 0.0) ? color / luminance : ColorRGB::white();
}

} /* bcr */ 
