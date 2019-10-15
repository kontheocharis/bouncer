#include "Mesh.hh"
#include <vector>
#include <array>
#include <stdexcept>
#include <iostream>

namespace bcr
{

Mesh::Mesh(
        const std::vector<Vec3>& vertices,
        const std::vector<std::array<int, 3>>& faces)
{
    // Each face is made of 3 vertices, so the whole thing must be divisible by 3
    std::vector<std::shared_ptr<Vertex>> temp_vertices;
    std::vector<std::shared_ptr<Face>> temp_faces;

    // Initalise all the faces
    for (auto& face : faces)
    {
        auto face_obj = std::make_shared<Face>();
        temp_faces.push_back(face_obj);
    }

    // Initialise all the vertices
    for (int i = 0; i < vertices.size(); ++i)
    {
        auto vert_obj = std::make_shared<Vertex>(vertices[i]);
        temp_vertices.push_back(vert_obj);

        // Initalise faces within vertices and vertices within faces
        for (int j = 0; j < faces.size(); ++j)
        {

            auto vertex_result = std::find(faces[j].begin(), faces[j].end(), i);

            if (vertex_result == std::end(faces[j]))
                continue;

            int vertex_index = std::distance(std::begin(faces[j]), vertex_result);

            temp_faces[j]->vertices[vertex_index] = vert_obj;
            vert_obj->faces.push_back(temp_faces[j]);
        }
    }

    this->m_faces = std::move(temp_faces);
    this->m_vertices = std::move(temp_vertices);
}

template<typename T>
std::vector<T> Mesh::map_faces(const std::function<T(Face&)>& func) const
{
    std::vector<T> vals;
    for (auto p_face : m_faces) {
        vals.push_back(func(*p_face));
    }
    return vals;
}

void Mesh::map_faces(const std::function<void(Face&)>& func) const
{
    for (auto p_face : m_faces) {
        func(*p_face);
    }
}

template<typename T>
std::vector<T> Mesh::map_vertices(const std::function<T(Vertex&)>& func) const
{
    std::vector<T> vals;
    for (auto p_vertex : m_vertices) {
        vals.push_back(func(*p_vertex));
    }
    return vals;
}

void Mesh::map_vertices(const std::function<void(Vertex&)>& func) const
{
    for (auto p_vertex : m_vertices) {
        func(*p_vertex);
    }
}

};
