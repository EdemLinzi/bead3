#ifndef TEXTEDIT_HPP_INCLUDED
#define TEXTEDIT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>



class TextEdit: public Widget {
protected:

    std::string _s;
    bool selected;
public:
    TextEdit(int x, int y, int sx, int sy,std::string _s);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual std::string ertek();
};

#endif
