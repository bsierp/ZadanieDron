#ifndef DNO_HH
#define DNO_HH
/*!
 * \file
 * \brief Definicja klasy Dno
 *
 * Plik zawiera definicje klasy Dno,
 * oraz deklaracje metod tej klasy.
 */
#include "Plaszczyzna.hh"
using drawNS::Point3D;
class Dno: public Plaszczyzna{
public:
Dno();
Dno(double max_x, double min_x, double max_y, double min_y,double z, drawNS::Draw3DAPI * api);
void Rysuj() override;
void Poziom(double level) override;
void Wymaz() override;

};
#endif