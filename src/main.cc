#include <iostream>

#include "Mesh.hh"
#include "Geometry.hh"
#include "Camera.hh"
#include "Scene.hh"
#include "Object.hh"

int main(int argc, char* argv[])
{
    bcr::Mesh my_mesh( 
            { {0, 0, 0}, {1, 1, 0}, {1, 0, 1}, {0, 0.5, 0.5} },
            { {0, 1, 2}, {0, 1, 3} }
        );

    return 0;
}
