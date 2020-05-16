#include "Dron.hh"
#include "GraniastoslupHex.hh"
#include <iostream>
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;
void wait4key() {                                                               
  do {                                                                          
    std::cout << "\n Press a key to continue..." << std::endl;                  
  } while(std::cin.get() != '\n');                                              
}        
int main(){
drawNS::Draw3DAPI * api = new APIGnuPlot3D(-20,20,-20,20,-20,20,0);
GraniastoslupHex hex(3,5,api);
hex.Rysuj();
wait4key();
hex.Ruszaj(5);
wait4key();
hex.Obroc(90);
wait4key();
hex.Wznies_Opusc(5);
hex.Wymaz();
wait4key();
/*Dron Orzel7(8,6,6,api);
wait4key();
Orzel7.rysuj_drona();
wait4key();
Orzel7.obrot_drona(90);
wait4key();
Orzel7.ruch_drona(5);
wait4key();
Orzel7.obrot_drona(90);
wait4key();
Orzel7.ruch_drona(-5);
wait4key();
Orzel7.obrot_drona(180);
wait4key();
Orzel7.wznies_opusc_drona(-5);
wait4key();
Orzel7.wymaz_drona();
wait4key();*/
delete(api);
}