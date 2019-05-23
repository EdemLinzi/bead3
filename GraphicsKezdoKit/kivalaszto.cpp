
#include "kivalaszto.hpp"
#include "graphics.hpp"
#include <string>
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;




Kivalaszto::Kivalaszto(int x, int y, int sx, int sy,int _Max,vector<string> _menunev)
    :Widget(x,y,sx,sy)
{
    Max=_Max;
    for(size_t i=0;i<_menunev.size();i++){
        menunev.push_back(_menunev[i]);
    }

    ssz=-1;
    elm=0;
    epy=-1;
    csn=(Max*Max)/(menunev.size()*_size_y);
    csl=((menunev.size()*(_size_y))/Max);

}

vector<string> Kivalaszto::vektor(){
    return menunev;
}

void Kivalaszto::ujvektor(vector<string> mnev){
    menunev.resize(mnev.size());
    for(size_t i=0;i<mnev.size();i++){
        menunev[i]=mnev[i];
    }
}

int Kivalaszto::kijelolt(){
    return ssz;
}


void Kivalaszto::uj(string nev){
    menunev.push_back(nev);
}

bool Kivalaszto::is_selected(int mouse_x,int mouse_y) const{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y &&  mouse_y<_y+Max;
}

void Kivalaszto::draw()const{
    double csn=(Max*Max)/(menunev.size()*_size_y);
    double csl=((menunev.size()*(_size_y))/Max);
    canvas c;
    c.open(_size_x,Max+_size_y+menunev.size()*(_size_y));
    c<<move_to(0,0)<<color(100,100,100)<<box(_size_x,_size_y+Max);
    c<<move_to(_size_x-10,elm+(_size_y))<<color(50,50,50)<<box(10,csn);
    for(size_t i=0;i<menunev.size();i++){
        if(ssz==i){
            c<<move_to(0,-elm*csl+i*(_size_y)+(_size_y))<<color(0,0,255)<<box(_size_x-10,_size_y)<<color(0,0,0)<<move_to(10,-elm*csl+_size_y+i*(_size_y)+15)<<text(menunev[i]);
        }
        else{
            c<<move_to(0,-elm*csl+i*(_size_y)+(_size_y))<<color(128,128,128)<<box(_size_x-10,_size_y)<<color(255,255,255)<<move_to(10,-elm*csl+_size_y+i*(_size_y)+15)<<text(menunev[i]);
        }
    }
    gout<<stamp(c,0,_size_y,_size_x,Max,_x,_y);

}

void Kivalaszto::handle(event ev)
{
    double csn=(Max*Max)/(menunev.size()*_size_y);
    double csl=((menunev.size()*(_size_y))/Max);
    for(size_t i=0;i<menunev.size();i++){
        if(ev.pos_x>=_x && ev.pos_x<=_x+_size_x-10 && ev.pos_y>-elm*csl+_y+i*(_size_y) && ev.pos_y<-elm*csl+_y+i*(_size_y)+_size_y && ev.button==btn_left){
            ssz=i;
        }
    }

    if(ev.pos_x>=_x+_size_x-10 && ev.pos_x<=_x+_size_x && ev.pos_y>_y+elm && ev.pos_y<_y+elm+csn && ev.button==btn_left){
        epy=ev.pos_y-elm;
        //std::cout<<"Csúszka";

    }
    if(ev.button==-btn_left){
            epy=-1;
            //std::cout<<"Elengedted";
        }
    if(epy!=-1 ){
        elm=ev.pos_y-epy;
    }
    if(ev.button==btn_wheelup && (elm>=0 && elm+csn<=Max) ){
        elm-=5;
    }
    if(ev.button==btn_wheeldown && (elm>=0 && elm+csn<=Max)){
        elm+=5;
    }
    if(elm<=0)
        elm=0;
    if((elm+csn)>Max && csn<Max)
        elm=Max-csn;


}

void Kivalaszto::torol(){
    for(size_t i=ssz;i<menunev.size()-1;i++){
        menunev[i]=menunev[i+1];

    }
    menunev.resize(menunev.size()-1);
}
