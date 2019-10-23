#include <iostream>

#include "mesh.hh"
#include "base.hh"
#include "camera.hh"
#include "scene.hh"

int main(int argc, char* argv[])
{
    Mesh my_mesh( 
            { {0, 0, 0}, {1, 1, 0}, {1, 0, 1}, {0, 0.5, 0.5} },
            { {0, 1, 2}, {0, 1, 3} }
        );

    return 0;
}
