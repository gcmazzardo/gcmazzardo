#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

#define PI 3,14
using namespace std;

class Biscoito{
private:
    double tam, preco;
    int forma;

public:

    Biscoito(){
        tam=0.0; forma=0; preco=0.0;
    }
    int getForma(){
        return forma;
    }
    void setForma(int x){
        forma = x;
    }
    double getTam(){
        return tam;
    }
    double setTam(double x){
        tam = x;
    }
    void setPreco(){
        if(retPorte(tam) == "Pequeno")
            preco = 0.50;
        else if(retPorte(tam) == "Medio")
            preco = 1.00;
        else
            preco = 1.50;
    }
    string retPorte(double area){
        if(area <= 0.33)
            return "Pequeno";
        else if(area > 0.33 && area <= 0.66)
            return "Medio";
        else
            return "Grande";
    }
    bool operator<(Biscoito& p) {
        return this->tam > p.getTam();
    }
};

class Retangulo: public Biscoito{
public:
    double retArea(double b){
        double h = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)+0.1; // altura random
        return b*h;
    }
};

class Triangulo: public Biscoito{
public:
    double retArea(double b){
        double h = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)+0.1; // altura random
        return b*h/2;
    }
};

class Circulo: public Biscoito{
public:
    double retArea(double r){
        return PI*(r*r);
    }
};

int main(){
    int n;
    cout << "Digite o numero de biscoitos:" << endl;
    cin >> n;

    vector<Biscoito> biscoitos;
    Triangulo x; Retangulo y; Circulo z;
    Biscoito aux;

    for(int i=0; i<n; i++){

        int formato = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/3)); //formato random
        double tamanho = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)+0.1; // tam random

        switch(formato){
            case 0: aux.setTam(x.retArea(tamanho)); break; // biscoito == triangulo, seta tamanho
            case 1: aux.setTam(y.retArea(tamanho)); break;// biscoito == retangulo, seta tamanho
            case 2: aux.setTam(z.retArea(tamanho)); break;// biscoito == circulo, seta tamanho
        }
        aux.setForma(formato);
        aux.setPreco();
        biscoitos.push_back(aux); //adiciona o novo biscoito ao vetor, com o devido tamanho, preço e formato.
    }

    sort(biscoitos.begin(), biscoitos.end()); //Ordenar em relaçao ao tamanho.

    cout << "Tamanhos dos biscoitos produzidos, do maior para o menor (cm2):" << endl;
    for(auto it = biscoitos.begin(); it!=biscoitos.end(); it++)
        cout << "   " << it->getTam() << endl;

    int pequenos=0, medios=0, grandes=0;
    for(auto it = biscoitos.begin(); it!=biscoitos.end(); it++){ //for pra contar a quantidade de cada biscoito, pelo tamanho
            auto x = it->retPorte(it->getTam());
            if(x == "Pequeno") pequenos++;
            if(x == "Medio") medios++;
            if(x == "Grande") grandes++;
    }
    cout << "Biscoitos:" << endl << "   Pequenos: " << pequenos << "   Total arrecadado: " << pequenos*0.50 << endl << "   Medios: " << medios << "   Total arrecadado: " << medios*1.00 << endl << "   Grandes: " << grandes << "   Total arrecadado: " << grandes*1.50 << endl;
    return 0;
}
