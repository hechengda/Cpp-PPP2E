#include "std_lib_facilities.h"

// 1
class Point
{
public:
    Point();
    Point(double px, double py);
    ~Point();

    double x;
    double y;

private:

};

// helper functions
istream& operator>>(istream& is, Point& p);
bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);

int main()
try {
    // 2
    cout << "Please enter 7 (x,y) pairs: ";
    vector<Point> original_points;
    for (Point p; cin>>p;) {
        original_points.push_back(p);
    }

    // 3 & 6
    for (const auto& p : original_points) {
        cout << '(' << p.x << ',' << p.y << ")\n";
    }

    // 4
    ofstream ost{"mydata.txt"};
    if (!ost) {
        error("can't open output file");
    }
    for (const auto& p : original_points) {
        ost << '(' << p.x << ',' << p.y << ")\n";
    }

    // 5
    ost.close();
    ifstream ist{"mydata.txt"};
    if (!ist) {
        error("can't open input file");
    }
    vector<Point> processed_points;
    for (Point p; ist >> p;) {
        processed_points.push_back(p);
    }

    // 6
    for (const auto& p : processed_points) {
        cout << '(' << p.x << ',' << p.y << ")\n";
    }

    // 7
    if (processed_points.size() != original_points.size()) {
        error("Something's wrong!");
    }
    for (size_t i = 0; i < original_points.size(); ++i) {
        if (processed_points[i] != original_points[i]) {
            error("Something's wrong!");
        }
    }

    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

// implementation of class Point
Point::Point() : x{0.0}, y{0.0}
{
}

Point::Point(double px, double py) : x{px}, y{py}
{
}

Point::~Point()
{
}

// implementation of helper functions
istream & operator>>(istream & is, Point & p)
{
    double x, y;
    char c1, c2, c3;
    is >> c1 >> x >> c2 >> y >> c3;
    if (!is) {
        return is;
    }
    if (c1!='(' || c2!=',' || c3!=')') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Point{x, y};
    return is;
}

bool operator==(const Point & p1, const Point & p2)
{
    return p1.x==p2.x && p1.y==p2.y;
}

bool operator!=(const Point & p1, const Point & p2)
{
    return !(p1 == p2);
}
