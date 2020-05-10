#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "Obiekt3D.hh"
class Prostopadloscian: public Obiekt3D {
    public:
    Prostopadloscian();
    void Rysuj(drawNS::Draw3DAPI *gplt)override ;
    Wektor <double,3> & operator[](int index);
    const Wektor <double,3> & operator[](int index) const;
    void zmien_wierzcholek(const Wektor <double,3> &Skl,int index) override;
};
std::istream & operator>>(std::istream &strm, Prostopadloscian & fig);
#endif