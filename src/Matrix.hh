#ifndef MATRIX_H
#define MATRIX_H

#include "Vec.hh"
#include <array>
#include <functional>
#include <type_traits>
#include <iostream>
#include <string>

namespace bcr
{

template<int M, int N>
class Matrix
{
public:
    Matrix(const std::array<std::array<double, M>,N>& data)
    {
        this->m_data = data;
    };

    // Apply a function to each of the matrix's elements.
    Matrix<M,N> map_elem(const std::function<double(double)>&) const;
    void map_elem(const std::function<void(double)>&) const;

    // Combine two matrices by the rule described by the 3rd argument.
    Matrix<M,N> combine(
            const Matrix<M,N>&,
            const std::function<double(double, double)>&) const;


    Matrix<M,N> operator+(const Matrix<M,N>&) const;
    Matrix<M,N> operator-(const Matrix<M,N>&) const;
    Matrix<M,N> operator-() const;

    Vec3 operator* (const Vec3&) const;

    Matrix<M,N>& operator+=(const Matrix<M,N>&);
    Matrix<M,N>& operator-=(const Matrix<M,N>&);

    // To string
    std::string to_string() const;

protected:
    std::array<std::array<double, M>, N> m_data;
};

class Matrix3 : virtual public Matrix<3, 3> 
{
public:
    Vec3 operator* (const Vec3&) const;
};

class Matrix2 : virtual public Matrix<2, 2>
{
public:
    Vec2 operator* (const Vec2&) const;
};

}

#endif /* MATRIX_H */
