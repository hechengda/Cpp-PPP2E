#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Simple_window win{{100, 100}, 800, 600, "Canvas"};

    Line h1{{100, 100}, {400, 100}};
    h1.set_color(Color::red);
    Line h2{{100, 200}, {400, 200}};
    h2.set_color(Color::white);
    Line h3{{100, 300}, {400, 300}};
    h3.set_color(Color::red);
    Line h4{{100, 400}, {400, 400}};
    h4.set_color(Color::white);

    Line v1{{100, 100}, {100, 400}};
    v1.set_color(Color::red);
    Line v2{{200, 100}, {200, 400}};
    v2.set_color(Color::white);
    Line v3{{300, 100}, {300, 400}};
    v3.set_color(Color::red);
    Line v4{{400, 100}, {400, 400}};
    v4.set_color(Color::white);

    win.attach(h1);
    win.attach(h2);
    win.attach(h3);
    win.attach(h4);
    win.attach(v1);
    win.attach(v2);
    win.attach(v3);
    win.attach(v4);

    win.wait_for_button();
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}