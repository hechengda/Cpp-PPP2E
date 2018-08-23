#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Simple_window win{{100, 100}, 600, 400, "Canvas"};

    Graph_lib::Rectangle r{{100, 100}, 100, 50};
    r.set_color(Color::blue);
    Graph_lib::Polygon po;
    po.add({100, 200});
    po.add({200, 200});
    po.add({200, 250});
    po.add({100, 250});
    po.set_color(Color::red);
    win.attach(r);
    win.attach(po);

    win.wait_for_button();
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}