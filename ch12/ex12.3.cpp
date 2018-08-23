#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Simple_window win{{100, 100}, 600, 400, "Canvas"};

    Text t1{{150, 200}, "H"};
    t1.set_color(Color::red);
    t1.set_font(Font::times_bold);
    t1.set_font_size(150);
    win.attach(t1);

    Text t2{{250, 200}, "C"};
    t2.set_color(Color::green);
    t2.set_font(Font::times_bold);
    t2.set_font_size(150);
    win.attach(t2);

    Text t3{{350, 200}, "D"};
    t3.set_color(Color::blue);
    t3.set_font(Font::times_bold);
    t3.set_font_size(150);
    win.attach(t3);

    win.wait_for_button();
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}