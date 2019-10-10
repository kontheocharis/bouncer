#ifndef MESH_H
#define MESH_H

#include "Vec3.hh"
#include <vector>
#include <array>
#include <memory>
#include <functional>

namespace bcr
{

struct Face;

struct Vertex
{
    Vec3 position;
    std::vector<std::unique_ptr<Face>> faces;
};

struct Face
{
    std::array<std::unique_ptr<Vertex>, 3> vertices;
};

class Mesh
{
    public:
        Mesh();

        void set_geometry(
                std::vector<std::array<double, 3>>& vertices,
                std::vector<std::array<int, 3>>& faces);

        void set_geometry(
                std::vector<Vec3>& vertices,
                std::vector<std::array<int, 3>>& faces);

        template<typename T>
        std::vector<T> map_faces(std::function<T(Face&)>) const;

        template<typename T>
        std::vector<T> map_vertices(std::function<T(Vertex&)>) const;

        virtual ~Mesh() {  };

    private:
        std::vector<Face> m_faces;
        std::vector<Vertex> m_vertices;
};

}
#endif /* MESH_H */
