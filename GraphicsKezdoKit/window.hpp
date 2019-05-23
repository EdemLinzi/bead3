#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <vector>
#include "widgets.hpp"


class Window {
protected:
    std::vector<Widget*> widgets;
public:
    void event_loop() ;
    void event_loop_al() ;
};



#endif // WINDOW_HPP_INCLUDED
