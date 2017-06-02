#ifndef WEKTORY_H
#define WEKTORY_H
#include <iostream>
using namespace std;

class Wektor
{
private:
    int dlugosc;
    int *wsk;

public:
    Wektor(int);
    Wektor(const Wektor&);
    ~Wektor();

    Wektor operator+(const Wektor&) const;
    Wektor operator-(const Wektor&) const;
    Wektor & operator=(const Wektor&);
    Wektor operator*(const Wektor&) const;
    Wektor operator*(const int&) const;
    Wektor & operator+=(const Wektor&);
    Wektor & operator-=(const Wektor&);
    Wektor & operator*=(const Wektor&);
    Wektor & operator*=(const int&);
    bool operator==(const Wektor&);
    bool operator!=(const Wektor&);
    int operator[](const int&);
    friend ostream & operator<<(ostream&, const Wektor&);
    friend istream & operator>>(istream&, Wektor&);
};


#endif
