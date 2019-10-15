#include <iostream>

#include "Matrix.hh"
#include "Vec.hh"
/* #include "Mesh.hh" */

int main(int argc, char* argv[])
{
    /* bcr::Vec2 v0 = {3, 7}; */
    /* bcr::Vec2 v1 = {4, 2}; */

    /* bcr::Mesh my_mesh( */ 
    /*         { bcr::Vec3 {0, 0, 0}, bcr::Vec3 {1,1,0}, bcr::Vec3 {1, 0, 1}, bcr::Vec3 {0,0.5,0.5} }, */
    /*         { {0, 1, 2}, {0, 1, 3} } */
    /*     ); */

    bcr::Matrix<3,3> my_mat({{
        {1, 3, 5},
        {6, 5, 2},
        {0, 1, 33},
    }});

    bcr::Vec3 my_vector = { 1, 1, 1 };

    std::cout << my_mat*my_vector << '\n';

    /* my_mesh.map_faces([](bcr::Face& face) -> void { */
    /*         std::cout << face.vertices[0]->position << "\n"; */
    /*         std::cout << face.vertices[1]->position << "\n"; */
    /*         std::cout << face.vertices[2]->position << "\n"; */
    /*     }); */

    return 0;
}
