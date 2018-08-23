#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Simple_window win{{100, 100}, 600, 400, "Canvas"};

    Graph_lib::Rectangle o_r{{0, 0}, 500, 400};
    o_r.set_fill_color(Color::red);
    win.attach(o_r);

    Graph_lib::Rectangle i_r{{50, 50}, 400, 300};
    i_r.set_fill_color(Color::cyan);
    win.attach(i_r);

    win.wait_for_button();
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}