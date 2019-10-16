#ifndef MESH_H
#define MESH_H

#include "Geometry.hh"

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

    Vertex(Vec3 position) : position(position) {};

    std::vector<std::shared_ptr<Face>> faces;
};

struct Face
{
    std::array<std::shared_ptr<Vertex>, 3> vertices;
};

class Mesh
{
public:
    Mesh(const std::vector<Vec3>& vertices, const std::vector<std::array<int, 3>>& faces);

    template<typename T>
    std::vector<T> map_faces(const std::function<T(const Face&)>&) const;

    void map_faces(const std::function<void(const Face&)>&) const;

    template<typename T>
    std::vector<T> map_vertices(const std::function<T(const Vertex&)>&) const;

    void map_vertices(const std::function<void(const Vertex&)>&) const;

    // Streaming
    friend std::ostream& operator<< (std::ostream& out, const Mesh& v); 

private:
    std::vector<std::shared_ptr<Face>> m_faces;
    std::vector<std::shared_ptr<Vertex>> m_vertices;
};

}

#endif /* MESH_H */
