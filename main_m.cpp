#include<iostream>
#include "macierze.h"
#include "wektory.h"
using namespace std;

int main ()
{
    int rozm;
    cout<<"Podaj wymiar macierzy\n";
    cin>>rozm;
    Matrix a(rozm, rozm);
    Matrix b(rozm, rozm);
    cout<<"Podaj 1. macierz\n";
    cin>>a;
    cout<<"Podaj 2. macierz\n";
    cin>>b;
    cout<<"Pierwsza macierz\n"<<a;
    cout<<"Druga macierz\n"<<b;
    Matrix c=a+b;
    Matrix d=a-b;
    Matrix e=a*2;
    cout<<a<<"+\n"<<b<<"=\n"<<c;
    cout<<a<<"-\n"<<b<<"=\n"<<d;
    cout<<a<<"*2\n"<<e;
    cout<<"Czy macierz a jest taka sama jak macierz b?"<<endl;
    if(a==b)
        cout<<"True\n";
    else
        cout<<"False\n";
    cout<<"Czy macierz a jest inna niz macierz b?"<<endl;
    if(a!=b)
        cout<<"True\n";
    else
        cout<<"False\n";

    a+=b;
    cout<<"\na+=b\n"<<a;
    a-=b;
    cout<<"a-=b\n"<<a;

    Matrix f=a*b;
    cout<<a<<"*\n"<<b<<"=\n"<<f;
    a*=2;
    cout<<"a*=2\n"<<a;
    return 0;
}
