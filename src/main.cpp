#include "Dron.hh"
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
drawNS::Draw3DAPI * api = new APIGnuPlot3D(-10,10,-10,10,-10,10,0);
Dron Orzel7(8,6,6,api);
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
wait4key();
delete(api);
}