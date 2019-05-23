#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>



class StaticText : public Widget {
protected:
    std::string _s;
public:
    StaticText(int x, int y, int sx, int sy,std::string _s);
    virtual void draw() const ;
    void setText(std::string szoveg){_s=szoveg;}
};
#endif // STATICTEXT_HPP_INCLUDED
