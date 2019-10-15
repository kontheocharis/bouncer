#include "Matrix.hh"
#include <sstream>

namespace bcr
{

template<int M, int N>
Matrix<M,N> Matrix<M,N>::map_elem(const std::function<double(double)>& func) const
{
    std::array<std::array<double, M>, N> new_data;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            new_data[i][j] = func(this->m_data[i][j]);
        }
    }

    return Matrix<N,M>(new_data);
}

template<int M, int N>
void Matrix<M,N>::map_elem(const std::function<void(double)>& func) const
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            func(this->m_data[i][j]);
        }
    }
}


template<int M, int N>
Matrix<M,N> Matrix<M,N>::combine(
        const Matrix<M,N>& a,
        const std::function<double(double, double)>& func) const
{
    std::array<std::array<double, M>, N> new_data;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            new_data[i][j] = func(this->m_data[i][j], a.m_data[i][j]);
        }
    }

    return Matrix<M,N>(new_data);
}

template<int M, int N>
Matrix<M,N> Matrix<M,N>::operator+(const Matrix<M,N>& a) const
{
    return this->combine(a, std::plus<double>());
}

template<int M, int N>
Matrix<M,N> Matrix<M,N>::operator-(const Matrix<M,N>& a) const
{
    return this->combine(a, std::minus<double>());
}

template<int M, int N>
Matrix<M,N> Matrix<M,N>::operator-() const
{
    return this->map_elem(std::negate<double>());
}

Vec3 Matrix3::operator* (const Vec3& a) const
{
    return { 
        this->m_data[0][0] * a.x + this->m_data[0][1] * a.y + this->m_data[0][2] * a.z,
        this->m_data[1][0] * a.x + this->m_data[1][1] * a.y + this->m_data[1][2] * a.z,
        this->m_data[2][0] * a.x + this->m_data[2][1] * a.y + this->m_data[2][2] * a.z
    };
}

Vec2 Matrix2::operator* (const Vec2& a) const
{
    return { 
        this->m_data[0][0] * a.x + this->m_data[0][1] * a.y,
        this->m_data[1][0] * a.x + this->m_data[1][1] * a.y
    };
}

template<int M, int N>
std::string Matrix<M,N>::to_string() const
{
    std::ostringstream out;
    out << "┌ ";

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            out << this->m_data[i][j];
            out << " ";
        }

        if (i != N-1) {
            if (i == 0) {
                out << "┐";
            } else {
                out << "│";
            }

            if (i + 1 == N - 1) {
                out << '\n';
                out << "└ ";
            } else {
                out << '\n';
                out << "│ ";
            }
        }
    }

    out << "┘";

    return out.str();
}

}
