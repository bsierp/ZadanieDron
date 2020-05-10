#ifndef DRON_HH
#define DRON_HH
#include "Interfejs.hh"

class Dron:public Prostopadloscian,public Interfejs{
    public:
    Dron();
    Dron(const Prostopadloscian & fig);
    void ruch_drona(const Wektor<double,3> & W,drawNS::Draw3DAPI *gplt) override;
    void obrot_drona(double kat_obr,drawNS::Draw3DAPI *gplt) override;
    void ruch_x(double x,drawNS::Draw3DAPI *gplt) override;
    void ruch_y(double y,drawNS::Draw3DAPI *gplt) override;
    void ruch_z(double z,drawNS::Draw3DAPI *gplt) override;
};

#endif