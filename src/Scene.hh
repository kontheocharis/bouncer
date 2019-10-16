#ifndef SCENE_H
#define SCENE_H

#include "Object.hh"

#include <vector>

namespace bcr
{

class Scene
{
public:
    std::vector<Object> objects;
    Scene(std::vector<Object> objects) : objects(objects) {};
};
    
} /* bcr */ 

#endif /* SCENE_H */
