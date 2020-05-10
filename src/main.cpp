#include "Dron.hh"
#include <fstream>
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
   // std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //shared_ptr nie działa
   drawNS::Draw3DAPI * api = new APIGnuPlot3D(-20,20,-20,20,-20,20,0);
  /* char wybor;
   
   cout<<"Prosze wybrac opcje:"<<endl<<"r-ruch dronem"<<endl<<"o-obrot drona"<<endl<<"q-wyjscie"<<endl;
   cin>>wybor;

   switch (wybor)
   {
   case 'r':
    {
      Wektor<double,3> W;
      cout<<"Podaj wspolrzedne wektora przesuniecia(3 liczby)"<<endl;
      cin>>W;
      break;
    }
    case 'o':
    { 
      double kat;
      cout<<"Podaj kat obrotu"<<endl;
      cin>>kat;
      break;
    }
    case 'q':
    {
      cout<<"Konczenie pracy programu"<<endl;
      delete api;
      return 0;
    }
    case ' ':
    break;
   
   default:
     {
     cout<<"Nie rozpoznano opcji"<<endl;
     break;
     }
   }*/
    std::fstream plik;
    plik.open("wsp");
    Prostopadloscian figura;
    plik>>figura;
    Dron drn(figura);
    //figura.Rysuj(api);
    drn.Rysuj(api);
    wait4key();
    /*for(int i=0;i<5;++i){
    drn.obrot_drona(360,api);
    wait4key();*/
    
   /* wait4key();*/
    drn.ruch_x(-6,api);
    wait4key();
    drn.ruch_x(-6,api);
    /*drn.ruch_z(-6,api);
    wait4key();
   drn.ruch_y(4,api);
    wait4key();*/
    //Wektor<double,3> Tst(6,-6,4);
   // drn.ruch_drona(Tst,api);
    wait4key();
    delete api;
}