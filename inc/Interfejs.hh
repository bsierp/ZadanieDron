#ifndef INTERFEJS_HH
#define INTERFEJS_HH
#include "Prostopadloscian.hh"
class Interfejs{
    protected:
    virtual void ruch_x(double x,drawNS::Draw3DAPI *gplt)=0;
    virtual void ruch_y(double y,drawNS::Draw3DAPI *gplt)=0;
    virtual void ruch_z(double z,drawNS::Draw3DAPI *gplt)=0;
    public:
    virtual void ruch_drona(const Wektor<double,3> & W,drawNS::Draw3DAPI *gplt)=0;
    virtual void obrot_drona(double kat_obr,drawNS::Draw3DAPI *gplt)=0;
};
#endif