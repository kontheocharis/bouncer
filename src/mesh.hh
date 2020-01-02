#pragma once

#include "eigen.hh"
#include <cmath>
#include <functional>

class Face;

class Vertex
{
    Vector3f m_position;
    std::vector<const Face*> m_adjacent_faces;
    friend class Mesh;
    Vertex() {}

public:
    const Vector3f& position() const { return m_position; }

    const std::vector<const Face*>& adjacent_faces() const { return m_adjacent_faces; }
};

class Face
{
    std::array<const Vertex*, 3> m_vertices;
    friend class Mesh;
    Face() {}

public:
    const Vertex& v0() const { return *m_vertices[0]; }
    const Vertex& v1() const { return *m_vertices[1]; }
    const Vertex& v2() const { return *m_vertices[2]; }

    const std::array<const Vertex*, 3>& vertices() const { return m_vertices; }
};

class Mesh
{
    std::vector<Vertex*> m_vertices;
    std::vector<Face*> m_faces;

public:
    Mesh(std::vector<Vector3f> raw_vertices, std::vector<std::array<size_t, 3>> raw_faces);

    const std::vector<Vertex*>& vertices() const { return m_vertices; }
    const std::vector<Face*>& faces() const { return m_faces; }

    // Constructor methods
    static Mesh plane(const std::array<Vector3f, 4> corners);

    ~Mesh();
};
