/*
13) Rotacionar uma lista uma posição.
Ex.: ?- rotacionar([1, 2, 3, 4, 5], L).
L = [2, 3, 4, 5, 1].
*/

rotacionar([N|L], LR) :- concatenar(L, [N], LR).

concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).