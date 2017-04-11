%OBI 2015 - Questão 1
%
% Questão 1. Para comemorar o aniversário de Cláudio, ele e mais quatro
% amigos – Alberto, Beto,
% Dino e Eurico – foram almoçar juntos no restaurante da escola. As mesas
% são redondas e acomodam
% exatamente cinco pessoas. Cláudio e Dino sentam-se um ao lado do outro.
% Alberto e Beto não
% sentam-se um ao lado do outro. Os dois amigos sentados ao lado de
% Eurico são:
%
% (A) Alberto e Beto (CORRETA)
% (B) Cláudio e Dino
% (C) Dino e Beto
% (D) Cláudio e Alberto
% (E) Alberto e Dino

aolado(X,Y,L) :- nextto(X,Y,L); nextto(Y,X,L).
aolado(X,Y,L) :- naspontas(X,Y,L).

naspontas(X,Y,L) :- L = [X|_], last(L,Y).
naspontas(X,Y,L) :- L = [Y|_], last(L,X).

solucao(X,Y):-
    A=[alberto,beto,claudio,dino,eurico],
    permutation(A,L),
    aolado(X,eurico,L),
    aolado(Y,eurico,L),
    aolado(claudio,dino,L),
    not(aolado(alberto,beto,L)).

%?- solucao(alberto,beto). %retornará true, é a correta.
%true

%?- solucao(claudio,dino).
%false.

%?- solucao(dino,beto).
%false.

%?- solucao(claudio,alberto).
%false.

%?- solucao(alberto,dino).
%false.



