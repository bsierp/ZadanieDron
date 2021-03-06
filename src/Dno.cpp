#include "Dno.hh"
Dno::Dno(){
        for(double &wymiar:granice){
        wymiar=0;
    }
}
Dno::Dno(double max_x, double min_x, double max_y, double min_y,double z, drawNS::Draw3DAPI * api){
    granice[0]=max_x;
    granice[1]=min_x;
    granice[2]=max_y;
    granice[3]=min_y;
    granice[4]=z;
    gplt=api;
}
void Dno::Wymaz(){
    this->gplt->erase_shape(this->id);
}
void Dno::Poziom(double level){
    this->granice[4]=level;
}
void Dno::Rysuj(){
    this->id=this->gplt->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(this->granice[0],this->granice[2],this->granice[4]), drawNS::Point3D(this->granice[0],0,this->granice[4]), drawNS::Point3D(this->granice[0],this->granice[3],this->granice[4])
	  },{
	drawNS::Point3D(this->granice[0]/2,this->granice[2],this->granice[4]), drawNS::Point3D(this->granice[0]/2,0,this->granice[4]), drawNS::Point3D(this->granice[0]/2,this->granice[3],this->granice[4])       
	  },{
	drawNS::Point3D(0,this->granice[2],this->granice[4]), drawNS::Point3D(0,0,this->granice[4]), drawNS::Point3D(0,this->granice[3],this->granice[4])       
	  },{
	drawNS::Point3D(this->granice[1]/2,this->granice[2],this->granice[4]), drawNS::Point3D(this->granice[1]/2,0,this->granice[4]), drawNS::Point3D(this->granice[1]/2,this->granice[3],this->granice[4])       
	  },{
	drawNS::Point3D(this->granice[1],this->granice[2],this->granice[4]), drawNS::Point3D(this->granice[1],0,this->granice[4]), drawNS::Point3D(this->granice[1],this->granice[3],this->granice[4])       
	  }},"yellow")+1;
}