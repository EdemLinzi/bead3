#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include <functional>
#include "widgets.hpp"

class PushButton :public Widget{
    protected:
        bool megnyomva;
        std::string cim;
    public:
        PushButton(int x,int y,int sx,int sy,std::string cim);
        virtual void draw() const;
        virtual void handle(genv::event ev) ;
        virtual void action()=0;
};


class FunctorButton: public PushButton{
    std::function<void()> _functor;
public:
    FunctorButton(int x,int y,int sx,int sy,std::string cim,std::function<void()> functor);
    void action();
};

#endif // PUSHBUTTON_HPP_INCLUDED
