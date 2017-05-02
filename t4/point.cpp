#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point{
private:
    double x;
    double y;

public:
    Point(){
        cout << "Novo ponto criado" << endl;
        x = y = 0.0;
    }

    Point(double x1, double y1){
        x=x1;
        y=y1;
    }

    void move(double dx, double dy){
        x = x+dx;
        y = y+dy;
    }

    double distanceTo(Point *p){
        return sqrt(pow((p->x-x),2)+pow((p->y-y),2));
    }
};

int main(){

    Point p1(6.2,10.4);
    vector<Point*> vet_pontos; // Fiz com vector, quero meus pontinhos extras! Hahah

    for(auto i=0; i<5; i++){
        vet_pontos.push_back(new Point(5+i,10+i));
        cout << "Distancia do ponto " << i << ": " << p1.distanceTo(vet_pontos[i]) << endl;
    }
}
