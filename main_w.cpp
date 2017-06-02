#include <iostream>
#include "wektory.h"

using namespace std;

int main()
{
    int s=0;
    cout<<"podaj rozmiar ";
    cin>>s;
    Wektor A(s);
    Wektor B(s);
    cout<<"podaj wartosci A "<<endl;
    cin>>A;
    cout<<"podaj wartosci B "<<endl;
    cin>>B;
    cout<<"oto wektor A "<<A<<endl;
    cout<<"oto wektor B "<<B<<endl;
    cout<<"oto suma A i B "<<A+B<<endl;
    cout<<"oto roznica A i B "<<A-B<<endl;
    cout<<"oto iloczyn A i B "<<A*B<<endl;
    cout<<"oto iloczyn A i liczby "<<A*6<<endl;
    A+=B;
    cout<<"oto A+=B "<<A<<endl;
    A-=B;
    cout<<"oto A-=B "<<A<<endl;
    A*=5;
    cout<<"oto A*=5 "<<A<<endl;
    A=B;
    cout<<"oto A = B "<<A<<endl;
    cout<<"trzeci wyraz A "<<A[1]<<endl;
    cout<<"Ola pozdrawiam ;) "<<endl;
    return 0;
}
