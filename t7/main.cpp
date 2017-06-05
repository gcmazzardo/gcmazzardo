#include <FL/fl_ask.H>
#include <stdexcept>
#include "t7.h"
#include <string>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

class Sorteio: public UserInterface{
private:
    int TotalParticipantes=0;
    int ParticipanteAtual=0;
    vector<int>Participantes;
    bool vetor_pronto = false;

public:    
    Sorteio() {
        btResetar->callback((Fl_Callback*) cbBtResetar, (void*)(this));	    
        btSortear->callback((Fl_Callback*) cbBtSortear, (void*)(this));
    }  

    void show() {
		w->show();
	}
    
    static void cbBtResetar(Fl_Widget* btn, void* userdata){          
        Sorteio* gui = static_cast<Sorteio*>(userdata);      
        gui->TotalParticipantes = 0; // reseta os atributos da classe, o vetor dos participantes e os Displays da GUI
        gui->ParticipanteAtual = 0;
        gui->Participantes.clear();
        gui->vetor_pronto = false;
        gui->Resultado->copy_label("");
        gui->DisplayResultado->copy_label("");
        gui->DisplayGanhador->copy_label("                                                   ");
    }
    static void cbBtSortear(Fl_Widget* btn, void* userdata){
        Sorteio* gui = static_cast<Sorteio*>(userdata);          
        try{
            int x = stoi(gui->numParticipantes->value()); // x = número de participantes digitado pelo usuário            
            gui->TotalParticipantes = x; //Total de participantes = número de participantes digitado pelo usuário
            if(gui->vetor_pronto == false){ //verifica se o vetor ja foi preenchido
                for(int i=1; i<=x; i++) // Acrescenta ao vetor todos os números de 1 a x participantes
                    gui->Participantes.push_back(i);
                    random_shuffle(gui->Participantes.begin(), gui->Participantes.end());
                    gui->vetor_pronto = true; // vetor preenchido com sucesso
            }        
        }catch (invalid_argument&) { // verifica se o número de participantes já foi inserido
		    fl_alert("Digite um valor antes de pressionar."); // se o número de participantes não foi inserido, mostra uma alerta
			return;
		}

        if(gui->ParticipanteAtual < gui->TotalParticipantes){
            gui->ParticipanteAtual++; // ParticipanteAtual++
            string nesimo_sorteado = to_string(gui->ParticipanteAtual); // Nésimo sorteado de inteiro para string              
            string x = to_string(gui->Participantes.back()); // x = ultimo elemento do vetor (sorteado da vez)    
            	gui->Participantes.pop_back(); // retira o ultimo elemento do vetor, que foi sorteado     
            string x_sorteado = "Ganhador nº: " + nesimo_sorteado;                
            gui->Resultado->copy_label(x.data()); // box do Resultado = num. sorteado (elemento retirado do vetor)                
            gui->DisplayGanhador->copy_label(x_sorteado.data()); //seta display "xº ganhador"
        }
        else
            fl_alert("O número de sorteios já foi esgotado."); // caso já tenham sido sorteados todos números, mostra uma alerta
    }
};

int main(){  
    Sorteio gui;
    gui.show();
    
    return Fl::run();
}
