#pragma once

#include "scene.hh"
#include "base.hh"
#include "camera.hh"

#include <vector>


// Implements Disney's Principled BRDF
struct DisneyOptions
{

};

std::vector<v4> trace_disney(const Scene& scene, const Camera& cam, const DisneyOptions& opts);

// Can add more tracers here
