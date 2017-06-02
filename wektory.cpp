#include <iostream>
#include "wektory.h"

using namespace std;

Wektor::Wektor(int dlg)
{
    if(dlg>1)
    {
        dlugosc=dlg;
        wsk= new int [dlugosc];
        if(wsk==NULL)
        {
            dlugosc=0;
            throw bad_alloc();
        }
        int i;
        for(i=0; i<dlugosc; i++)
        {
            wsk[i]=0;
        }
    }
    else
    {
        cout<<"Dlugosc nie moze byc mniejsza od 2"<<endl;
        cout<<"Nadaje wektorowi dlugosc 2"<<endl;
        dlugosc=2;
        wsk= new int [2];
        if(wsk==NULL)
        {
            dlugosc=0;
            throw bad_alloc();
        }
        int i;
        for(i=0; i<2; i++)
        {
            *wsk=0;
            wsk++;
        }
    }
}

Wektor::Wektor(const Wektor &wktr)
{
    dlugosc=wktr.dlugosc;
    wsk= new int [dlugosc];
    if(wsk==NULL)
    {
        dlugosc=0;
        throw bad_alloc();
    }
    int i;
    for(i=0; i<dlugosc; i++)
    {
        wsk[i]=wktr.wsk[i];
    }
}

Wektor::~Wektor()
{
    delete [] wsk;
}

Wektor Wektor::operator+(const Wektor &t) const
{
    Wektor suma(dlugosc);
    if(dlugosc==t.dlugosc)
    {
        int i;
        for(i=0; i<dlugosc; i++)
            suma.wsk[i]=wsk[i]+t.wsk[i];
    return suma;
    }
}

Wektor Wektor::operator-(const Wektor &t) const
{
    Wektor roznica(dlugosc);
    if(dlugosc==t.dlugosc)
    {
        int i;
        for(i=0; i<dlugosc; i++)
            roznica.wsk[i]=wsk[i]-t.wsk[i];
    return roznica;
    }
}

Wektor &Wektor::operator=(const Wektor &t)
{
    if(this==&t) return *this;
    else
    {
        delete []wsk;
        dlugosc=t.dlugosc;
        wsk= new int [dlugosc];
        int i;
        for(i=0; i<dlugosc; i++)
            wsk[i]=t.wsk[i];
        return *this;
    }
}

Wektor Wektor::operator*(const Wektor &t) const //wektor*wektor
{
    Wektor iloczyn(dlugosc);
    if(dlugosc==t.dlugosc)
    {
        int i;
        for(i=0; i<dlugosc; i++)
            iloczyn.wsk[i]=wsk[i]*t.wsk[i];
    return iloczyn;
    }
}

Wektor Wektor::operator*(const int &liczba) const //wektor*liczba
{
    Wektor nowy(dlugosc);
    int i;
    for(i=0; i<dlugosc; i++)
        nowy.wsk[i]=wsk[i]*liczba;
    return nowy;
}

Wektor &Wektor::operator+=(const Wektor &t)
{
    if(dlugosc==t.dlugosc)
    {
        int i;
        for(i=0; i<dlugosc; i++)
            wsk[i]+=t.wsk[i];
        return *this;
    }
}

Wektor &Wektor::operator-=(const Wektor &t)
{
    if(dlugosc==t.dlugosc)
    {
        int i;
        for(i=0; i<dlugosc; i++)
            wsk[i]-=t.wsk[i];
        return *this;
    }
}

Wektor & Wektor::operator*=(const Wektor &t)
{
    if(dlugosc==t.dlugosc)
    {
        int i;
        for(i=0; i<dlugosc; i++)
            wsk[i]*=t.wsk[i];
        return *this;
    }
}

Wektor &Wektor::operator*=(const int &liczba)
{
    int i;
    for(i=0; i<dlugosc; i++)
        wsk[i]*=liczba;
    return *this;
}

bool Wektor::operator==(const Wektor &t)
{
    if(dlugosc!=t.dlugosc) return false;
    else
    {
        int i;
        for(i=0; i<dlugosc; i++)
        {
            if(wsk[i]!=t.wsk[i]) return false;
        }
    return true;
    }
}

bool Wektor::operator!=(const Wektor &t)
{
    if(dlugosc!=t.dlugosc) return true;
    else
    {
        int i;
        for(i=0; i<dlugosc; i++)
        {
            if(wsk[i]!=t.wsk[i]) return true;
        }
    return false;
    }
}

int Wektor::operator[](const int &indeks)
{
    if(indeks<dlugosc) return wsk[indeks];
    else cout<<"Podany indeks nie miesci sie w tablicy";
}

std::ostream &operator<<(ostream & os, const Wektor &t)
{
    int i;
    for(i=0; i<t.dlugosc; i++)
    {
        os<<t.wsk[i]<<" ";
    }
    return os;
}

std::istream &operator>>(istream & is, Wektor &t)
{
    int i;
    for(i=0; i<t.dlugosc; i++)
    {
        is>>t.wsk[i];
    }
    return is;
}

