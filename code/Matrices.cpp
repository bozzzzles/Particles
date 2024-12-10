#include "Matrices.h"
namespace Matrices
{
Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    a.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        a.at(i).resize(cols);
        for (int j = 0; j < cols; j++)
        {
            a.at(i).at(j) = 0;
        }
    }
}

Matrix operator+(const Matrix &a, const Matrix &b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        throw runtime_error("Error: dimensions must agree");
    }
    Matrix c(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            c(i, j) = a(i, j) + b(i, j);
        }
    }
    return c;
}

Matrix operator*(const Matrix &a, const Matrix &b)
{
    if (a.getCols() != b.getRows())
    {
        throw runtime_error("Error: dimensions must agree");
    }
    Matrix c(a.getRows(), b.getCols());
    for (int k = 0; k < b.getCols(); k++)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            double sum = 0;
            for (int j = 0; j < a.getCols(); j++)
            {
                sum += a(i, j) * b(j, k);
            }
            c(i, k) = sum;
        }
    }
    return c;
}

bool operator==(const Matrix &a, const Matrix &b)
{
    bool same = true;
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        same = false;
    }
    for (int i = 0; i < a.getRows() && same; i++)
    {
        for (int j = 0; j < a.getCols() && same; j++)
        {
            if (abs(a(i, j) - b(i, j)) >= 0.001)
                same = false;
        }
    }
    return same;
}

bool operator!=(const Matrix &a, const Matrix &b)
{
    return !(a == b);
}

ostream &operator<<(ostream &os, const Matrix &a)
{
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            os << a(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
{
    (*this)(0, 0) = cos(theta);
    (*this)(0, 1) = -(sin(theta));
    (*this)(1, 0) = sin(theta);
    (*this)(1, 1) = -(cos(theta));
}

ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
{
    (*this)(0, 0) = scale;
    (*this)(0, 1) = 0;
    (*this)(1, 0) = 0;
    (*this)(1, 1) = scale;
}

TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
{
    for (int i = 0; i < nCols; i++)
    {
        (*this)(0, i) = xShift;
        (*this)(1, i) = yShift;
    }
}
}