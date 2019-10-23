#pragma once

#include "base.hh"

#include <vector>
#include <array>
#include <memory>
#include <functional>

struct Face;

struct Vertex
{
    v3 position;

    Vertex(v3 position) : position(position) {};

    std::vector<std::shared_ptr<Face>> faces;
};

struct Face
{
    std::array<std::shared_ptr<Vertex>, 3> vertices;
};

struct Mesh
{
    std::vector<std::shared_ptr<Face>> m_faces;
    std::vector<std::shared_ptr<Vertex>> m_vertices;

    Mesh(const std::vector<v3>& vertices, const std::vector<std::array<int, 3>>& faces);
    friend std::ostream& operator<< (std::ostream& out, const Mesh& v); 
};
