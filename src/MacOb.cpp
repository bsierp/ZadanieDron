#include "MacOb.hh"
MacOb::MacOb(){
     for(int i=0;i<3;i++){                                                 
        for(int j=0;j<3;j++){                                             
        tab[i][j]=0;                                                            
        }
}
}
//Tylko obrot w z
MacOb::MacOb(double skl){
    kat=skl;
    tab[0][0]=cos(kat*PI/180);
    tab[0][1]=-sin(kat*PI/180);
    tab[1][0]=sin(kat*PI/180);
    tab[1][1]=cos(kat*PI/180);
    tab[2][2]=1;
}
Wektor<double,3> MacOb::operator*(const Wektor<double,3> & W) const{
    Wektor<double,3> wynik;
    for(int i=0;i<3;i++){                                                
         wynik[i]=this->tab[i]*W;
}
return wynik;
}
void MacOb::zmien_kat(double skl){
    MacOb pom(skl);
    *this=pom;
}