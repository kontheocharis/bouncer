#include <iostream>
#include "Vec3.hh"


int main(int argc, char *argv[])
{
    bcr::Vec3 v1(13, 1.44, 37);
    bcr::Vec3 v2(0.42, 13, 1.01);

    v1.normalize();

    auto v3 = v2.cross(v1) + v1;

    std::cout << v1 << "\n" << v2 << "\n";

    std::cout << v3.dot(-v2 * 2) << "\n";
    return 0;
}
