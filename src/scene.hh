#pragma once
#include "camera.hh"
#include "entity.hh"

class Scene
{
public:
    const std::vector<IEntity>& entities() const;
    const Camera& camera() const;
};
