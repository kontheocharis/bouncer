#pragma once

#include "base.hh"

struct Camera
{
    Transform view_matrix;

    int pixel_width;
    int pixel_height;

    double focal_length = 1.0;
    double field_of_view = 60;
};
