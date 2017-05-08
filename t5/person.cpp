#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

class Pontuacao{
private:
    int total=0;
public:
    Pontuacao(){
        total=0;
    }
    int getTotal(){
        return total;
    }
    setTotal(int x){
        this->total = this->total+x;
    }
};

class Person {
private:
    string nome;
    string descricao;
    Pontuacao pontuacao;

public:

    Person(string nome, string descricao, int pontos) {
        this->nome = nome;
        pontuacao.setTotal(pontuacao.getTotal()+pontos);
        this->descricao = descricao;
    }
    string getName() {
        return nome;
    }
    string getDescricao() {
        return descricao;
    }
    int getPontuacao(){
        return pontuacao.getTotal();
    }
    Pontuacao retPontuacao(){
        return pontuacao;
    }

    //compara pela idade
    bool operator<(Person& p) {
        return this->pontuacao.getTotal() > p.pontuacao.getTotal();
    }

};

//compara pelo nome
bool cmpPersonName(Person& p1, Person& p2) {
   return p1.getName() < p2.getName();
}

//compara pelos pontos
bool cmpPersonPoints(Person& p1, Person& p2) {
   return p1.getPontuacao() < p2.getPontuacao();
}

int main(){

    ifstream data("data.csv");

    string linha, cell[3];
    vector<Person> pessoas;

    while(getline(data, linha)){

        stringstream linestream(linha);
        getline(linestream, cell[0], '|');
        getline(linestream, cell[1], '|');
        getline(linestream, cell[2], '|');
        pessoas.push_back(Person(cell[0], cell[1], atoi(cell[2].c_str())));
    }

    sort(pessoas.begin(), pessoas.end()); //Ordenando o vetor em relaçao às pontuações em atividades, da maior para a menor pontuação

    vector<Person>::iterator it;
    for (it = pessoas.begin(); it != pessoas.end(); it++) // for para printar o Nome/Descricao/Pontuacao das atividades, que estão ordenadas da maior para a menor pontuaçao
        cout<< it->getName() << " | " << it->getDescricao() << " | " << it->getPontuacao() << endl;
    cout << endl;


    sort(pessoas.begin(), pessoas.end(), cmpPersonName); //Ordenar o nome em relação ao nome.

    for (it = pessoas.begin(); it != pessoas.end(); it++) //for pra printar os nomes e o total da pontuação da pessoa.
        cout<< it->getName() << " | "  << it->getPontuacao() << endl;
    cout << endl;

    sort(pessoas.begin(), pessoas.end(), cmpPersonPoints); //Ordenar o nome em relação à pontuação, da menor para a maior pontuação.

    for (it = pessoas.begin(); it != pessoas.end(); it++) //for pra printar os nomes e o total da pontuação da pessoa.
        cout<< it->getName() << " | "  << it->getPontuacao() << endl;
    cout << endl;

    return 0;
}
