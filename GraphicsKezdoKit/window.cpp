#include "window.hpp"

using namespace genv;

void Window::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        gout<<move_to(0,0)<<color(0,0,50)<<box(800,600);
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}

void Window::event_loop_al() {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_backspace) {
        gout<<move_to(0,0)<<color(0,0,50)<<box(800,600);
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}


