
#include "PushButton.hpp"

#include<iostream>

using namespace genv;

PushButton::PushButton(int x, int y, int sx, int sy,std::string _cim)
    : Widget(x,y,sx,sy)
{
    megnyomva=false;
    cim=_cim;
    std::cout<<gout.twidth(_cim);
    if(gout.twidth(_cim)>_size_x){
       _size_x=gout.twidth(_cim)+10;
    }
}

void PushButton::draw() const
{
    if(megnyomva){
        gout << move_to(_x+5, _y+5) << color(255,255,255) << box(_size_x, _size_y);
        gout << color(0,0,255)<< move_to(_x+9,_y+25)<<text(cim);
    }
    else{
        gout << move_to(_x+5, _y+5) << color(100,100,100) << box(_size_x, _size_y);
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << color(0,0,255)<< move_to(_x+4,_y+20)<<text(cim);
    }
}

void PushButton::handle(event ev) {
    if(is_selected(ev.pos_x,ev.pos_y) && ev.button==btn_left){
        megnyomva=!megnyomva;
        action();
    }
    if(ev.button==-btn_left)
    {
      megnyomva=!megnyomva;
    }
}

FunctorButton::FunctorButton(int x,int y,int sx,int sy,std::string cim,std::function<void()> functor)
:PushButton(x,y,sx,sy,cim),_functor(functor)
{
}

void FunctorButton::action(){
    _functor();
}
