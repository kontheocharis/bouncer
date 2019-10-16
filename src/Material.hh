#ifndef MATERIAL_H
#define MATERIAL_H

namespace bcr
{

struct ColorRGB
{
    double R, G, B;

    ColorRGB operator+ (const ColorRGB&) const;
    ColorRGB operator- (const ColorRGB&) const;
    ColorRGB operator- () const;

    ColorRGB operator* (const ColorRGB&) const;

    double dot(const ColorRGB&) const;

    ColorRGB operator* (double) const;
    ColorRGB operator/ (double) const;

    static ColorRGB white() { return ColorRGB {1, 1, 1}; };
    static ColorRGB black() { return ColorRGB {0, 0, 0}; };
};

struct Material
{
    ColorRGB albedo;
    double subsurface;
    double metallic;
    double specular;
    double specular_tint;
    double roughness;
    double anisotropic;
    double sheen;
    double sheen_tint;
    double clearcoat;
    double clearcoat_gloss;
};

}

#endif /* MATERIAL_H */
