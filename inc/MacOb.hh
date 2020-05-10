#ifndef MACOB_HH
#define MACOB_HH
#include "Mac.hh"
class MacOb:Macierz<double,3>{
  double kat;
  public:
  MacOb();
  MacOb(double skl);
  Wektor<double,3> operator*(const Wektor<double,3> & W) const;
  double zwroc_kat() const{return this->kat;}
  void zmien_kat(double skl);
};
#endif