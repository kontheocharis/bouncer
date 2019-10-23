#pragma once

#include "base.hh"

struct DisneyMaterial
{
    v4 albedo;
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
