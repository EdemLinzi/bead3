#include <sstream>
#include "textedit.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

TextEdit::TextEdit(int x, int y, int sx, int sy,string s)
    : Widget(x,y,sx,sy)
{
     _s=s;
     selected=false;
}
void TextEdit::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    /*if (selected) {
        gout << color(255,255,255)<< move_to(_x+gout.twidth(_s)+3,_y+5)<<box(5,20);
    }*/
    gout << color(255,255,255)<< move_to(_x+gout.twidth(_s)+3,_y+5)<<box(5,20);
    gout << color(255,255,255)<< move_to(_x+3,_y+20)<<text(_s);
}
void TextEdit::handle(event ev)
{
    /*if(ev.type == ev_mouse&&is_selected(ev.pos_x, ev.pos_y)){
        selected=true;
    }
    else{
        selected=false;
    }*/
    if(ev.type==ev_key && ev.keycode >= 32 && ev.keycode <= 162){
        char c=ev.keycode;
        _s+=c;
    }
    if(gout.twidth(_s)+5>=_size_x){
        _s.resize(_s.length()-1);
    }
    if(ev.keycode==key_enter){
        _s="";
    }
    if(ev.keycode==key_backspace && _s.length() != 0){
        _s.resize(_s.length()-1);
    }
}

string TextEdit::ertek(){
    return _s;
}
