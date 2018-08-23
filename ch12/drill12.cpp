#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try {
    Simple_window win{{100, 100}, 600, 400, "My window"};

    Point o{20, 300};
    Axis ax{Axis::x, o, 280, 10, "x axis"};
    win.attach(ax);
    Axis ay{Axis::y, o, 280, 10, "y axis"};
    ay.set_color(Color::cyan);
    ay.label.set_color(Color::dark_red);
    win.attach(ay);

    Function sine{sin, 0, 100, {20, 150}, 1000};
    sine.set_color(Color::blue);
    win.attach(sine);

    Graph_lib::Polygon po;
    po.add({300, 200});
    po.add({350, 100});
    po.add({400, 200});
    po.set_color(Color::red);
    //po.set_style(Line_style::dash);
    po.set_style({Line_style::dash, 4});
    win.attach(po);

    Graph_lib::Rectangle r{{200, 200}, 100, 50};
    r.set_fill_color(Color::yellow);
    win.attach(r);

    Closed_polyline cpo;
    cpo.add({100, 50});
    cpo.add({200, 50});
    cpo.add({200, 100});
    cpo.add({100, 100});
    cpo.add({50, 75});
    cpo.set_style({Line_style::dash, 2});
    cpo.set_fill_color(Color::green);
    win.attach(cpo);

    Text t{{150, 150}, "Hello, graphical world!"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    // Use the absolute path instead, and don't forget to escape '\' on Windows
    Image jpg{{100, 50}, "image.jpg"};
    jpg.move(100, 200);
    win.attach(jpg);

    Circle c{{100, 200}, 50};
    Graph_lib::Ellipse e{{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m{{100, 200}, 'x'};
    win.attach(c);
    win.attach(e);
    win.attach(m);

    ostringstream oss;
    oss<<"screen size: "<<x_max()<<"*"<<y_max()
        <<"; window size: "<<win.x_max()<<"*"<<win.y_max();
    Text sizes{{100, 20}, oss.str()};
    win.attach(sizes);

    Image gif{{255, 255}, "snow_cpp.gif"};
    gif.set_mask({40, 40}, 200, 150);
    win.attach(gif);

    win.set_label("Canvas #12");
    win.wait_for_button();
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}
