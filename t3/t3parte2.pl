% Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a
% soma dos quadrados de X e Y.
somaQuad(X,Y,Z):-Z is X*X+Y*Y.

% Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista que
% inicia com o número 0 (zero).
zeroInit(L):-L=[0|_].

% Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas
% L1 e L2 possuírem o mesmo primeiro elemento.
hasEqHeads(L1,L2):-
    nth0(0,L1,X),
    nth0(0,L2,Y),
    X=:=Y.

% Defina um predicado has5(L) que seja verdadeiro se L for uma lista de 5
% elementos. Lembre de como funciona a unificação em Prolog e resolva
% este exercício sem usar o predicado pré-definido length
has5(L):-
    L = [_,_,_,_,_].

% Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista de
% N elementos. Agora você pode usar um predicado pré-definido.
hasN(L,N):-
    length(L, X),
    X=N.

%Defina um predicado mesmaPosicao(A,L1,L2) para verificar se um elemento
%A está na mesma posição nas listas L1 e L2. Assuma que L1 e L2 sejam
%permutações de uma lista de elementos distintos, sem repetições. Dica:
%procure auxílio em predicados pré-definidos. Exemplo de uso:
mesmaPosicao(C,L1,L2):-
    nth0(X, L1, C),
    nth0(Y, L2, C),
    X=:=Y.

% Defina um predicado isBin(L) que seja verdadeiro se L for uma lista
% contendo somente elementos 0 e 1. Use recursão.
isBin([]).
isBin([H|T]) :-
    member(H,[0,1]),
    isBin(T).

% Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for
% composta por exatamente 5 repetições do elemento E. Não use recursão.
repete5(E,L):-
    length(L,X),
    delete(L,E,L2),
    length(L2,Y),
    X is Y+5.

% Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S
% for o somatório dos quadrados dos elementos da lista L.
sumQuads([],0).
sumQuads([H|T], S) :-
    X is S-H*H,
    sumQuads(T, X).

% Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a
% lista L for composta por exatamente N repetições do elemento E.
repete(0,_,[]).
repete(N,E,[H|T]):-
    H\=E,
    repete(N,E,T).
repete(N,E,[H|T]):-
    H=E,
    Aux is N-1,
    repete(Aux,E,T).


%Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x da lista L1.
mapop([],[]).
mapop(L1,L2):-
    L1=[H1|T1],
    L2=[H2|T2],
    H2 is 2*H1+1,
    mapop(T1,T2).

%Defina um predicado positivos(L1,L2), de forma que L2 seja uma lista só com os elementos positivos de L1, conforme o exemplo abaixo:
positivos([],[]).
positivos([H1|T1],[H1|T2]):-
        H1 > 0,
        positivos(T1,T2).
positivos([H1|T1],L2):-
        H1 =< 0,
        positivos(T1,L2).
