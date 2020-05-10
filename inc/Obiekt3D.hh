#ifndef OBIEKT_3D
#define OBIEKT_3D
#include "MacOb.hh"
#include "Dr3D_gnuplot_api.hh"
using std::vector;
using drawNS::Point3D;   
class Obiekt3D {
    protected:
    vector<Wektor<double,3> >wierzcholki;
    MacOb orient;
    int id;
    public:
    virtual void Rysuj(drawNS::Draw3DAPI *gplt)=0;
    virtual void zmien_wierzcholek(const Wektor <double,3> &Skl,int index)=0;
};
#endif