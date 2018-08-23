#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Simple_window win{{100, 100}, 600, 400, "Canvas"};

    Graph_lib::Rectangle r{{100, 100}, 100, 30};
    Text t{{150, 115}, "Howdy!"};
    win.attach(r);
    win.attach(t);

    win.wait_for_button();
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}