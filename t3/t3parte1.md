%Considere a seguinte base de fatos e regras:

[trace] ?-avo(joao,y).
%Faz a chamada do predicado "avo" com o valor "joao" e a variável "Y".

Call: (8) avo(joao, _7222) ? creep  
%Variável "Y" agora é um identificador.

Call: (9) pai(joao, _7442) ? creep
%Faz a chamada agora do predicado "pai" e substitui a variável por "jose"

Exit: (9) pai(joao, jose) ? creep
%Retorna substituindo com "jose" e o identificador de "Y"

Call: (9) pai(jose, _7222) ? creep
%Faz a chamada de "pai" com o valor "jose" e o identificador de "Y"

Fail: (9) pai(jose, _7222) ? creep
%Retorna false porque não consegue resolver "Y" no predicado "pai"

Fail: (8) avo(joao, _7222) ? creep
%Retorna false porque não consegue resolver "Y" no predicado "avo"

false.

[trace]  ?- avo(roberto,Y).  
%Faz a chamada do predicado "avo" com o valor "roberto" e a variável Y.

Call: (8) avo(roberto, _7224) ? creep
%Variável "Y" agora é um identificador.

Call: (9) pai(roberto, _7444) ? creep
%Faz a chamada agora do predicado "pai" com o valor "roberto" e um identificador.

Exit: (9) pai(roberto, joao) ? creep 
%Retorna a resolução do identificador do predicado "pai" com o valor "joao".

Call: (9) pai(joao, _7224) ? creep
%Faz a chamada de "pai" com o valor "joao"e identificador.

Exit: (9) pai(joao, jose) ? creep
%Retorna a resolução do predicado da variável "Y" com o valor "jose"

Exit: (8) avo(roberto, jose) ? creep
%Retorna que "Y" é igual a "jose" do predicado

Y=jose ;

Redo: (9) pai(roberto, _7444) ? creep
%Executa novamente o predicado "avo" e chama "pai" e "roberto" como valor

Exit: (9) pai(roberto, julio) ? creep
%Substitui o identificador por "julio" e retorna de "pai".

Call: (9) pai(julio, _7224) ? creep 
%Faz de novo a chamada de "pai" com o valor "Julio" e um identificador.

Exit: (9) pai(julio, marcos) ? creep
%Identificador é substituido por "marcos" e retorna de "pai"

Exit: (8) avo(roberto, marcos) ? creep
%Retorna que "Y" é igual a "marcos" do predicado "avo".

Y=marcos ;

Redo: (9) pai(julio, _7224) ? creep 
%Executa novamente o predicado "avo" e chama "pai" e "julio" como valor

Exit: (9) pai(julio, mario) ? creep
%O identificador é substituido pelo valor "mario" e retorna de "pai".

Exit: (8) avo(roberto, mario) ? creep
%Retorna que "Y" é igual a "mario" do predicado "avo".

Y=mario.

%===================================================================================================================

%Considere o predicado definido abaixo, que resolve um problema de uma prova da Olimpíada Brasileira de Informática.

[trace]  ?- azulejos(120,A).
Faz a chamada do predicado "azulejos" com valor "120" e a variável "A"

Call: (8) azulejos(120, _7232) ? creep
%Variavel A se torna um identificador

Call: (9) 120>0 ? creep 
%Testa se 120 é maior que 0

Exit: (9) 120>0 ? creep
%Verdadeiro

Call: (9) _7460 is floor(sqrt(120)) ? creep
%Faz uma definição para o valor do identificador

Exit: (9) 10 is floor(sqrt(120)) ? creep    
%Define o valor do identificador

Call: (9) _7472 is 120-10*10 ? creep 
%Faz uma definição para o valor do identificador

Exit: (9) 20 is 120-10*10 ? creep
%Define o valor do identificador

Call: (9) azulejos(20, _7474) ? creep
%Faz a chamada do predicado "azulejos" usando o valor do identificador

Call: (10) 20>0 ? creep
%Testa se 20>0

Exit: (10) 20>0 ? creep
%Verdadeiro

Call: (10) _7480 is floor(sqrt(20)) ? creep
%Faz a definição para o valor do identificador

Exit: (10) 4 is floor(sqrt(20)) ? creep
%Define o valor do identificador

Call: (10) _7492 is 20-4*4 ? creep
%Faz a definição para o valor do identificador

Exit: (10) 4 is 20-4*4 ? creep
%Define o valor do identificador

Call: (10) azulejos(4, _7494) ? creep
%Faz a chamada do predicado "azulejos" usando o valor do identifcador

Call: (11) 4>0 ? creep
Testa se 4>0

Call: (11) 4>0 ? creep
Verdadeiro

Call: (11) _7500 is floor(sqrt(4)) ? creep
%Faz a definição para o valor do identificador

Exit: (11) 2 is floor(sqrt(4)) ? creep   
%Define o valor do identificador

Call: (11) _7512 is 4-2*2 ? creep
%Faz a definição para o valor do identificador

Exit: (11) 0 is 4-2*2 ? creep
%Define o valor do identificador

Call: (11) azulejos(0, _7514) ? creep
%Chama o predicado "azulejos" com um identificador

Exit: (11) azulejos(0, 0) ? creep
%Resolve o predicado "azulejos" cujo azulejos(0,0)

Call: (11) _7518 is 1+0 ? creep   
%Tenta fazer definiçao para o valor do identificador

Exit: (11) 1 is 1+0 ? creep
%Define o valor do identificador

Exit: (10) azulejos(4, 1) ? creep 
%Consegue com sucesso

Call: (10) _7524 is 1+1 ? creep
%Tenta fazer a definição para o valor do predicado

Exit: (10) 2 is 1+1 ? creep 
%Define o valor do predicado

Exit: (9) azulejos(20, 2) ? creep
%Consegue com sucesso

Call: (9) _7232 is 1+2 ? creep 
%Teta fazer a definiçao do valor para o identificador

Exit: (9) 3 is 1+2 ? creep
%Define o valor do identificador.

Exit: (8) azulejos(120, 3) ? creep
%Faz o retorno de "azulejos" com A=3

A = 3.

%===========================================================================================

%Escolha algum predicado recursivo que esteja nos slides ou em qualquer outra fonte. Faça a execução passo-a-passo de uma consulta com o predicado escolhido. 
%Lembre-se de mostrar o código do predicado no seu arquivo t3parte1.md


%Usarei o exercício 6 do t3parte2. Fonte: Eu mesmo.

IsBin([]).
isBin([H|T]) :-
    member(H,[0,1]),
    isBin(T).

%Consulta:

trace: ?- isBin([0,1,0]
%Faz a chamada do predicado isBin com a lista [0,1,0]

Call: (8) isBin([0, 1, 0]) ?
%Faz a chamada do predicado IsBin com os valores [0,1,0]

Call: (9) lists:member(0, [0, 1]) ? 
%Verifica se o primeiro elemento da lista(0) está na lista [0,1]

Exit: (9) lists:member(0, [0, 1]) ?
%Retorna que 0 está na lista [0,1]

Call: (9) isBin([1, 0]) ? 
%Chama recursivamente o predicado IsBin, agora com a lista dos valores restantes [1,0]

Call: (10) lists:member(1, [0, 1]) ? 
%Verifica se o valor da lista (1) está na lista [0,1]

Exit: (10) lists:member(1, [0, 1]) ? 
%Retorna que 1 está na lista [0,1]

Call: (10) isBin([0]) ? 
%Chama recursivamente o predicado IsBin, agora com o valor restante [0]

Call: (11) lists:member(0, [0, 1]) ? 
%Verifica se o valor da lista(0) está na lista [0,1]

Exit: (11) lists:member(0, [0, 1]) ? 
%Retorna que 0 está na lista [0,1]

Call: (11) isBin([]) ? 
%Chama recursivamente o predicato IsBin para uma lista vazia

Exit: (11) isBin([]) ? 
%Retorna para predicado IsBin

Exit: (10) isBin([0]) ?
%Retorna verdadeiro de isBin para [0]

Exit: (9) isBin([1, 0]) ?
%Retorna verdadeiro de isBin para [1,0]

Exit: (8) isBin([0, 1, 0]) ?
%Retorna verdadeiro de isBin para [0,1,0], que é a lista

true.







