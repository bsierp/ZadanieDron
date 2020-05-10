#include"Dron.hh"
void Dron::obrot_drona(double kat_obr,drawNS::Draw3DAPI *gplt){
    this->orient.zmien_kat(kat_obr);
    MacOb Mac(1);
    int pomkat;
    for(pomkat=0;pomkat<kat_obr;++pomkat){
    for(int i=0;i<8;++i){
        gplt->erase_shape(this->id);
        zmien_wierzcholek(Mac*this->wierzcholki[i],i);
        (*this).Rysuj(gplt);
        }
    }
    Mac.zmien_kat(-(pomkat-kat_obr));
    for(int i=0;i<8;++i){
        gplt->erase_shape(this->id);
        zmien_wierzcholek(Mac*this->wierzcholki[i],i);
        (*this).Rysuj(gplt);
    }
}
//Dla testu czy dziala
Dron::Dron(const Prostopadloscian & fig){
    for(int i=0;i<8;++i){
       (*this).zmien_wierzcholek(fig[i],i);
    }
}
void Dron::ruch_z(double z,drawNS::Draw3DAPI *gplt){
double j;//zmiennna do uplynniania ruchu
if(z>0){
    for(j=0;j<z;j+=0.1){
        for(int i=0;i<8;++i){
            gplt->erase_shape(this->id);
            this->wierzcholki[i][2]+=0.1;
            (*this).Rysuj(gplt);
        }
    }
    for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
            this->wierzcholki[i][0]+=-(z-j);
            (*this).Rysuj(gplt);
    }
   
}
else if(z<0){
    for(j=0;j>z;j-=0.1){
        for(int i=0;i<8;++i){
            gplt->erase_shape(this->id);
            this->wierzcholki[i][2]+=-0.1;
            (*this).Rysuj(gplt);
        }
    }
    for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
            this->wierzcholki[i][0]+=-(z-j);
            (*this).Rysuj(gplt);
}
}
}
void Dron::ruch_x(double x,drawNS::Draw3DAPI *gplt){
    double j;
    if(x<0){
        (*this).obrot_drona(360-(this->orient.zwroc_kat()-90),gplt);
        for(j=0;j>x;j-=0.1){
        for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
                this->wierzcholki[i][0]+=-0.1;
                (*this).Rysuj(gplt);
                
            }
            }
           for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
            this->wierzcholki[i][0]+=-(x-j);
            (*this).Rysuj(gplt);
           }
           this->orient.zmien_kat(90);
    }
    else if(x>0){
        (*this).obrot_drona(360-(90+this->orient.zwroc_kat()),gplt);
        for(j=0;j<x;j+=0.1){
            for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
                this->wierzcholki[i][0]+=0.1;
                (*this).Rysuj(gplt);
            }
        }
        for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
            this->wierzcholki[i][0]+=-(x-j);
            (*this).Rysuj(gplt);
           }
           this->orient.zmien_kat(270);
    }
    
}
void Dron::ruch_y(double y,drawNS::Draw3DAPI *gplt){
    double j;
    double epsilon=0.00000001;
    if(y<0){
        (*this).obrot_drona(360-(this->orient.zwroc_kat()-180),gplt);
        for(j=0;j>y;j-=0.1){
        for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
                this->wierzcholki[i][1]+=-0.1;
                (*this).Rysuj(gplt);
                
            }
            }
           for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
            this->wierzcholki[i][1]+=-(y-j);
            (*this).Rysuj(gplt);
           }
           this->orient.zmien_kat(180);
    }
    else if(y>0){
        if(this->orient.zwroc_kat()<epsilon)
        this->orient.zmien_kat(360);
        (*this).obrot_drona(360-(this->orient.zwroc_kat()),gplt);
        for(j=0;j<y;j+=0.1){
            for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
                this->wierzcholki[i][1]+=0.1;
                (*this).Rysuj(gplt);
            }
        }
        for(int i=0;i<8;++i){
                gplt->erase_shape(this->id);
            this->wierzcholki[i][1]+=-(y-j);
            (*this).Rysuj(gplt);
           }
            this->orient.zmien_kat(0);
    }
}
void Dron::ruch_drona(const Wektor<double,3> & W,drawNS::Draw3DAPI *gplt){
(*this).ruch_x(W[0],gplt);
(*this).ruch_y(W[1],gplt);
(*this).ruch_z(W[2],gplt);
}
