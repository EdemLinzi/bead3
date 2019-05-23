#include "statictext.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

StaticText::StaticText(int x, int y, int sx, int sy,string s)
    :Widget(x,y,sx,sy)
{
    _s=s;
}
void StaticText::draw() const
{
    ///Boxos kirajzolás
    /*gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << color(255,255,255)<< move_to(_x+4,_y+20)<<text(_s);*/
    ///Csak szöveg
    gout << color(255,255,255)<< move_to(_x,_y)<<text(_s);

}


