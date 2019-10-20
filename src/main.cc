#include <iostream>

#include "Mesh.hh"
#include "Geometry.hh"
#include "Camera.hh"
#include "Scene.hh"
#include "Object.hh"
#include <Tracer.hh>

int main(int argc, char* argv[])
{
    bcr::Mesh my_mesh( 
            { {0, 0, 0}, {1, 1, 0}, {1, 0, 1}, {0, 0.5, 0.5} },
            { {0, 1, 2}, {0, 1, 3} }
        );

    my_mesh.map_vertices([&](const bcr::Vertex& v) -> void {
    });

    bcr::Camera camera({1920, 1080});
    camera.set_settings({1250, 323});

    return 0;
}
