/*
8) Reverter uma lista. Dica: use o predicado concatenar.
Ex.: ?- reverter([1, 2, 3], L).
L = [3, 2, 1].
*/

reverter([],[]).
reverter([N|L], LR) :- reverter(L, LREVERSA), concatenar(LREVERSA, [N], LR).
    
concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).