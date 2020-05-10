#include "Prostopadloscian.hh"
void Prostopadloscian::zmien_wierzcholek(const Wektor<double,3> &Skl,int index){
    this->wierzcholki[index]=Skl;
}
Prostopadloscian::Prostopadloscian(){
    Wektor<double,3> W;
for(int i=0;i<8;++i){
    this->wierzcholki.push_back(W);
}
}//Do testow
const Wektor<double,3> & Prostopadloscian::operator[](int index) const{
     if (index<0&&index>8)
    {                                                 
       std::cerr<<"Wierzcholek poza zakresem"<<std::endl;                          
        exit(1);                                                                
    }                                                                           
    return this->wierzcholki[index];
} 
void Prostopadloscian::Rysuj(drawNS::Draw3DAPI *gplt){
  
this->id=gplt->draw_polyhedron(vector<vector<Point3D> > {{                                         
        drawNS::Point3D(this->wierzcholki[0][0],this->wierzcholki[0][1],this->wierzcholki[0][2]), drawNS::Point3D(this->wierzcholki[1][0],this->wierzcholki[1][1],this->wierzcholki[1][2]), drawNS::Point3D(this->wierzcholki[2][0],this->wierzcholki[2][1],this->wierzcholki[2][2]),drawNS::Point3D(this->wierzcholki[3][0],this->wierzcholki[3][1],this->wierzcholki[3][2])             
      },{                                                                                  
        drawNS::Point3D(this->wierzcholki[4][0],this->wierzcholki[4][1],this->wierzcholki[4][2]), drawNS::Point3D(this->wierzcholki[5][0],this->wierzcholki[5][1],this->wierzcholki[5][2]), drawNS::Point3D(this->wierzcholki[6][0],this->wierzcholki[6][1],this->wierzcholki[6][2]),drawNS::Point3D(this->wierzcholki[7][0],this->wierzcholki[7][1],this->wierzcholki[7][2])             
          }},"blue");
}
//Do testow
Wektor<double,3> & Prostopadloscian::operator[](int index){
    if (index<0&&index>8)
    {                                                 
       std::cerr<<"Wierzcholek poza zakresem"<<std::endl;                          
        exit(1);                                                                
    }                                                                           
    return this->wierzcholki[index];
}
//Do testow
std::istream & operator>>(std::istream &strm, Prostopadloscian & fig){
    Wektor <double,3> pom;
    for(int i=0;i<8;++i){
        strm>>pom;
        fig.zmien_wierzcholek(pom,i);
    }
    return strm;
}