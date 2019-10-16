#include "Material.hh"
#include <cmath>
#include <algorithm>

namespace bcr
{

ColorRGB ColorRGB::operator+(const ColorRGB& c) const
{
    return { std::min(1.0, this->R + c.R), std::min(1.0, this->G + c.G), std::min(1.0, this->B + c.B) };
}

ColorRGB ColorRGB::operator-(const ColorRGB& c) const
{
    return { std::max(0.0, this->R - c.R), std::max(0.0, this->G - c.G), std::max(0.0, this->B - c.B) };
}

ColorRGB ColorRGB::operator*(const ColorRGB& c) const
{
    return { this->R * c.R, this->G * c.G, this->B * c.B };
}

ColorRGB ColorRGB::operator*(double a) const
{
    return { this->R * a, this->G * a, this->B * a };
}

ColorRGB ColorRGB::operator/(double a) const
{
    return { this->R / a, this->G / a, this->B / a };
}

double ColorRGB::dot(const ColorRGB& c) const
{
    return ( this->R * c.R + this->G * c.G + this->B * c.B );
}

}
