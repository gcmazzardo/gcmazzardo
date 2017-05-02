#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    double x;
    double y;

public:
    Point(){
        x = y = 0.0;
    }

    Point(double x1, double y1) {
        x = x1;
        y = y1;
    }

    double distanceTo(Point *p){
        return sqrt(pow((p->x-x),2)+pow((p->y-y),2));
    }
};

class Circle {
private:
    Point p;
    double r;

public:
    Circle(double x1, double y1, double r1){
        p = Point(x1, y1); r = r1;
     }

    double distanceTo(Circle *c){
        Point paux = c->p;
        return p.distanceTo(&paux) - c->r - r;
    }
};

int main() {
    Circle c1(10,20,5), c2(20,30,3);
    cout << "Distancia entre os circulos: " << c1.distanceTo(&c2) << endl;
    return 0;
}
