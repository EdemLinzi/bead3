#ifndef SZAMLALO_HPP_INCLUDED
#define SZAMLALO_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>

class Szamlalo:public Widget{
protected:
        int lertek,ertek;
        std::string sertek;
        int max,min;
        bool korbeforde;
    public:
        Szamlalo(int x,int y,int sx,int sy,int max,int min,bool _korbeforde);
        virtual void draw() const;
        virtual void handle(genv::event ev);
        virtual std::string adat();
        virtual int szam();
};


#endif // SZAMLALO_HPP_INCLUDED
