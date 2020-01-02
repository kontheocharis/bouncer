#include "mesh.hh"

Mesh::Mesh(std::vector<Vector3f> raw_vertices, std::vector<std::array<size_t, 3>> raw_faces)
{
    m_vertices.resize(raw_vertices.size());
    m_faces.resize(raw_faces.size());

    for (size_t i = 0; i < raw_vertices.size(); ++i) {
        m_vertices[i] = new Vertex();
        m_vertices[i]->m_position = raw_vertices[i];
    }

    for (size_t i = 0; i < m_faces.size(); ++i) {
        m_faces[i] = new Face();
        m_faces[i]->m_vertices = { { m_vertices[raw_faces[i][0]],
                                     m_vertices[raw_faces[i][1]],
                                     m_vertices[raw_faces[i][2]] } };

        m_vertices[raw_faces[i][0]]->m_adjacent_faces.push_back(m_faces[i]);
        m_vertices[raw_faces[i][1]]->m_adjacent_faces.push_back(m_faces[i]);
        m_vertices[raw_faces[i][2]]->m_adjacent_faces.push_back(m_faces[i]);
    }
}

Mesh Mesh::plane(const std::array<Vector3f, 4> corners)
{
    return Mesh(std::vector(corners.begin(), corners.end()), { { 0, 1, 2 }, { 2, 3, 1 } });
}

Mesh::~Mesh()
{
    for (Vertex* v : m_vertices) {
        delete v;
    }
    for (Face* f : m_faces) {
        delete f;
    }
}
