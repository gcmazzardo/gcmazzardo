%OBI 2015 - Quest�o 1
%
% Quest�o 1. Para comemorar o anivers�rio de Cl�udio, ele e mais quatro
% amigos � Alberto, Beto,
% Dino e Eurico � foram almo�ar juntos no restaurante da escola. As mesas
% s�o redondas e acomodam
% exatamente cinco pessoas. Cl�udio e Dino sentam-se um ao lado do outro.
% Alberto e Beto n�o
% sentam-se um ao lado do outro. Os dois amigos sentados ao lado de
% Eurico s�o:
%
% (A) Alberto e Beto (CORRETA)
% (B) Cl�udio e Dino
% (C) Dino e Beto
% (D) Cl�udio e Alberto
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

%?- solucao(alberto,beto). %retornar� true, � a correta.
%true

%?- solucao(claudio,dino).
%false.

%?- solucao(dino,beto).
%false.

%?- solucao(claudio,alberto).
%false.

%?- solucao(alberto,dino).
%false.



