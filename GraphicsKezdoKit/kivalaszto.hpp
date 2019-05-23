#ifndef KIVALASZTO_HPP_INCLUDED
#define KIVALASZTO_HPP_INCLUDED

#include <vector>
#include <string>
#include "graphics.hpp"
#include "widgets.hpp"

using namespace std;


class Kivalaszto:public Widget{
protected:
        double ssz;
        double elm;
        double epy;
        double Max;
        double csn;
        double csl;
    public:
        vector<string> menunev;
        Kivalaszto(int x,int y,int sx,int sy,int Max,vector<string> menunev);
        virtual void draw() const;
        virtual void handle(genv::event ev) ;
        virtual bool is_selected(int mx,int my) const;
        virtual void torol();
        virtual int kijelolt();
        virtual void uj(string nev);
        virtual void ujvektor(vector<string> nev);
        virtual vector<string> vektor();
};




#endif // KIVALASZTO_HPP_INCLUDED
