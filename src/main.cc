#include <iostream>
#include <memory>

#include "eigen.hh"
#include "mesh.hh"
#include "camera.hh"

int main(int argc, char* argv[])
{
    Mesh mesh(
        {
            Vector3f::UnitX(),
            Vector3f::UnitY(),
            Vector3f::UnitZ(),
        },
        { { 0, 1, 2 } });

    for (Vertex* v : mesh.vertices())
    {
        std::cout << v->position().x() << '\n';
    }

    return 0;
}
