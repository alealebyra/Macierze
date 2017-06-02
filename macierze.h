#ifndef MACIERZE_H
#define MACIERZE_H
#include <iostream>
#include "wektory.h"
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    Wektor **wsk;

public:
    Matrix(int, int);
    Matrix(const Matrix&);
    ~Matrix();

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    Matrix operator*(const int&) const;
    Matrix & operator=(const Matrix&);
    Matrix & operator+=(const Matrix&);
    Matrix & operator-=(const Matrix&);
    Matrix & operator*=(const Matrix&);
    Matrix & operator*=(const int&);
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);
    Wektor operator[](const int&);
    friend ostream & operator<<(ostream&, const Matrix&);
    friend istream & operator>>(istream&, Matrix&);
};

#endif
