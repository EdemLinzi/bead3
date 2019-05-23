#include <iostream>
#include <sstream>
#include "szamlalo.hpp"
#include "graphics.hpp"

using namespace genv;

Szamlalo::Szamlalo(int x, int y, int sx, int sy,int _max,int _min,bool _korbeforde)
    :Widget(x,y,sx,sy)
{
    max=_max;
    min=_min;
    lertek=0;
    ertek=0;
    sertek="0";
    korbeforde=_korbeforde;
}


std::string Szamlalo::adat(){
    return sertek;
}

int Szamlalo::szam(){
    return ertek;
}


void Novelo_gomb(int kx,int ky,int sz,int m){
    gout<<move_to(kx+sz-m/2+2,ky+2)<<color(255,255,255)<<box(m/2-4,m/2-4);
    gout<<move_to(kx+sz-m/2+4,ky+m/4-2)<<color(0,0,0)<<box(m/2-8,5);
    gout<<move_to(kx+sz-m/4-3,ky+2+2)<<color(0,0,0)<<box(5,m/2-8);
}

void Csokkento_gomb(int kx,int ky,int sz,int m){
    gout<<move_to(kx+sz-m/2+2,ky+m/2+2)<<color(255,255,255)<<box(m/2-4,m/2-4);
    gout<<move_to(kx+sz-m/2+4,ky+m/2+m/4-2)<<color(0,0,0)<<box(m/2-8,5);
}


void Szamlalo::draw() const{
    //Box
    gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x-_size_y/2,_size_y);
    gout<<move_to(_x+4,_y+4)<<color(0,0,0)<<box(_size_x-_size_y/2-8,_size_y-8);

    //Plusz Gomb
    Novelo_gomb(_x,_y,_size_x,_size_y);
    //Minusz Gomb
    Csokkento_gomb(_x,_y,_size_x,_size_y);

    gout<<move_to(_x+5,_y+_size_y/2+4)<<color(255,255,255)<<text(sertek);
}



void Szamlalo::handle(event ev)
{

    if(lertek!=0){
        lertek=0;
    }
    if(ev.button==btn_left){
    if(ev.pos_x>=_x+_size_x-_size_y/2+2 && ev.pos_x<=_x+_size_x-2 && ev.pos_y>=_y+2 && ev.pos_y<=_y+2+_size_y/2-4){
         lertek=1;
        //return lertek=1;
    }
    else if(ev.pos_x>=_x+_size_x-_size_y/2+2 && ev.pos_x<=_x+_size_x-2 && ev.pos_y>=_y+_size_y/2+2 && ev.pos_y<=_y+_size_y/2+_size_y/2-2){
         lertek=-1;
        //return lertek=-1;
    }
    }
    else if(ev.keycode==key_up){
         lertek=1;
        //return lertek=1;
    }
    else if(ev.keycode==key_down){
         lertek=-1;
        //return lertek=-1;
    }
    else if(ev.keycode==key_pgup){
        lertek=10;
        //return lertek=10;
    }
    else if(ev.keycode==key_pgdn){
         lertek=-10;
        //return lertek=-10;
    }
    else
    {
         lertek=0;
        //return lertek=0;
    }
    ertek=ertek+lertek;
if(korbeforde){
    if(ertek>max){
        ertek=min;
    }
    if(ertek<min){
        ertek=max;
    }
}
else{
    if(ertek>=max){
        ertek=max;
    }
    if(ertek<=min){
        ertek=min;
    }
}
    std::stringstream ss;
    ss<<ertek;
    ss>>sertek;

}

