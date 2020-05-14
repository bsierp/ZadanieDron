#include "Dron.hh"
Dron::Dron(double width, double length, double height, drawNS::Draw3DAPI *api){
if(width>0&&length>0&&height>0){
    wym[0]=width;
    wym[1]=length;
    wym[2]=height;
    gplt=api;
    }
    else
    {
        cerr<<"Wprowadzono niedodatnia dlugosc boku"<<endl;
        exit(1);
    }

}
void Dron::rysuj_drona(){
    (*this).Rysuj();
}
void Dron::wymaz_drona(){
    (*this).Wymaz();
}
void Dron::ruch_drona(double odl){
    double j;
    if(odl>=0){
    for(j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY);
}
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));
    }
    else
    {
    (*this).obrot_drona(180);
    odl*=(-1);
    for(j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY);
}
    (*this).Ruszaj(DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));

    }
    
}
void Dron::obrot_drona(double kat_obr){
    double pomkat;
    for(pomkat=0;pomkat<=kat_obr;pomkat+=DRONE_ROTATION_FREQUENCY){
        (*this).Obroc(DRONE_ROTATION_FREQUENCY);
    }
    (*this).Obroc(DRONE_ROTATION_FREQUENCY*(1-((pomkat-kat_obr)/DRONE_ROTATION_FREQUENCY)));
}
void Dron::wznies_opusc_drona(double odl){
    double j;
    if(odl>=0){
    for(j=0;j<=odl;j+=DRONE_MOVEMENT_FREQUENCY){
        (*this).Wznies_Opusc(DRONE_MOVEMENT_FREQUENCY);
    }
    (*this).Wznies_Opusc(DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));    
    }
    else
    {
    for(j=0;j>=odl;j-=DRONE_MOVEMENT_FREQUENCY){
        (*this).Wznies_Opusc(DRONE_MOVEMENT_FREQUENCY);
    }
    (*this).Wznies_Opusc(-DRONE_MOVEMENT_FREQUENCY*(1-((j-odl)/DRONE_MOVEMENT_FREQUENCY)));
    }
    
}