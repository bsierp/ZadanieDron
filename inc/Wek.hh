#ifndef WEK_HH
#define WEK_HH
#include <cmath>
#include <iostream>
using std::cerr;
using std::endl;
template<class TYP, int ROZMIAR>
class Wektor{
    TYP tab[ROZMIAR];
    public:
    Wektor();
    Wektor(TYP x,TYP y,TYP z):tab{x,y,z}{}
    const TYP & operator[](int index) const;
    TYP & operator[](int index);
    Wektor operator+(const Wektor<TYP,ROZMIAR> & W2) const;
    Wektor operator-(const Wektor<TYP,ROZMIAR> & W2) const;
    TYP operator*(const Wektor<TYP,ROZMIAR> & W2) const;
    Wektor operator*(TYP skl) const;
    bool operator==(const Wektor<TYP,ROZMIAR> & W2) const;
    bool operator!=(const Wektor<TYP,ROZMIAR> & W2) const;
    double dlugosc() const{
         return sqrt(*this * *this);
    }
};
template<class TYP, int ROZMIAR>                                                
std::istream & operator>>(std::istream & strm, Wektor<TYP,ROZMIAR> & W);
template<class TYP, int ROZMIAR>          
std::ostream & operator<<(std::ostream & strm,const Wektor<TYP,ROZMIAR> & W);
#endif