#include <iostream>
#include "macierze.h"
#include "wektory.h"

using namespace std;

Matrix::Matrix(int w, int k)
{
    row=w;
    col=k;
    wsk= new Wektor* [row];
    int i;
    for(i=0; i<row; i++)
    {
        *(wsk+i)= new Wektor(col);
    }
}

Matrix::Matrix(const Matrix & mac)
{
    row=mac.row;
    col=mac.col;
    wsk= new Wektor* [row];
    int i;
    for(i=0; i<row; i++)
    {
        wsk[i]=new Wektor(col); //??
        *(wsk[i])=*(mac.wsk[i]);
    }
}

Matrix::~Matrix()
{
    int i;
    for(i=0; i<row; i++)
    {
        delete wsk[i];
    }
    delete [] wsk;
}

Matrix Matrix::operator+(const Matrix &t) const
{
    Matrix suma(row, col);
    if(row==t.row && col==t.col)
    {
        int i;
        for(i=0; i<row; i++)
            *(suma.wsk[i])=*(wsk[i]) + *(t.wsk[i]);
        return suma;
    }
}

Matrix Matrix::operator-(const Matrix &t) const
{
    Matrix roznica(row, col);
    if(row==t.row && col==t.col)
    {
        int i;
        for(i=0; i<row; i++)
            *(roznica.wsk[i])=*(wsk[i]) - *(t.wsk[i]);
        return roznica;
    }
}

Matrix Matrix::operator*(const Matrix &t) const
{
    Matrix iloczyn(row, col);
    if(row==t.row && col==t.col)
    {
        int i;
        for(i=0; i<row; i++)
            *(iloczyn.wsk[i])=*(wsk[i]) * (*(t.wsk[i]));
        return iloczyn;
    }
}

Matrix Matrix::operator*(const int &liczba) const
{
    Matrix iloczyn(row, col);
    int i;
    for(i=0; i<row; i++)
        *(iloczyn.wsk[i])=*(wsk[i]) * liczba;
    return iloczyn;
}

Matrix & Matrix::operator=(const Matrix &t)
{
    if(this==&t) return *this;
    else
    {
        int i;
        for(i=0; i<row; i++)
            delete [] wsk[i];
        delete [] wsk;

        row=t.row;
        col=t.col;
        wsk= new Wektor* [row];
        for(i=0; i<row; i++)
        {
            wsk[i]= new Wektor(col);
            *(wsk[i])=*(t.wsk[i]);
        }
        return *this;
    }
}

Matrix &Matrix::operator+=(const Matrix &t)
{
    if(row==t.row && col==t.col)
    {
        int i;
        for(i=0; i<row; i++)
            *(wsk[i])+=(*(t.wsk[i]));
        return *this;
    }
}

Matrix &Matrix::operator-=(const Matrix &t)
{
    if(row==t.row && col==t.col)
    {
        int i;
        for(i=0; i<row; i++)
            *(wsk[i])-=(*(t.wsk[i]));
        return *this;
    }
}

Matrix &Matrix::operator*=(const Matrix &t)
{
    if(row==t.row && col==t.col)
    {
        int i;
        for(i=0; i<row; i++)
            *(wsk[i])*=(*(t.wsk[i]));
        return *this;
    }
}

Matrix &Matrix::operator*=(const int &liczba)
{
        int i;
        for(i=0; i<row; i++)
            *(wsk[i])*=liczba;
        return *this;
}

bool Matrix::operator==(const Matrix &t)
{
    if(row!=t.row || col!=t.col) return false;
    else
    {
        int i;
        for(i=0; i<row; i++)
        {
            if(*(wsk[i])!= *(t.wsk[i])) return false;
        }
        return true;
    }
}

bool Matrix::operator!=(const Matrix &t)
{
    if(row!=t.row || col!=t.col) return true;
    else
    {
        int i;
        for(i=0; i<row; i++)
        {
            if(*(wsk[i])!= *(t.wsk[i])) return true;
        }
        return false;
    }
}

Wektor Matrix::operator[](const int &indeks)
{
    return (*(wsk[indeks]));
}

std::ostream &operator<<(ostream & os, const Matrix &t)
{
    os<<endl;
    int i;
    for(i=0; i<t.row; i++)
    {
        os<<*(t.wsk[i])<<" ";
        os<<endl;
    }
    os<<endl;
    return os;
}

std::istream &operator>>(istream & is, Matrix &t)
{
    int i;
    for(i=0; i<t.row; i++)
    {
        is>>*(t.wsk[i]);
    }
    return is;
}
