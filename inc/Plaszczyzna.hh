#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH
using std::vector;
/*!
 * \file
 * \brief Definicja klasy abstrakcyjnej Plaszczyzna
 *
 * Plik zawiera definicje klasy abstrakcyjnej Plaszczyzna,
 * oraz deklaracje wirtualnych metod tej klasy.
 */
#include "Obiekt3D.hh"
/*!
* \brief Model pojęcia Płaszczyzna
*
* Klasa modeluje pojęcie płaszczyzny
* dziedzicząc publicznie po klasie Obiekt3D.
*/
class Plaszczyzna:public Obiekt3D{
protected:
double granice[5];
public:
virtual void Poziom(double level)=0;
};
#endif