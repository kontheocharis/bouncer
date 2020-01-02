#pragma once

#include "eigen.hh"

class Color : public Vector4f
{
public:
    Color(float r, float g, float b, float a) : Vector4f(r, g, b, a) {}
    Color(float r, float g, float b) : Vector4f(r, g, b, 1.0) {}
    Color(const Vector4f& color) : Vector4f(color) {}
    Color(const Vector3f& color, float alpha) : Vector4f(color(0), color(1), color(2), alpha) {}

    float& r() { return this->x(); }
    float& g() { return this->y(); }
    float& b() { return this->z(); }
    float& a() { return this->w(); }

    const float& r() const { return this->x(); }
    const float& g() const { return this->y(); }
    const float& b() const { return this->z(); }
    const float& a() const { return this->w(); }
};
