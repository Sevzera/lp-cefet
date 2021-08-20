/*
10) Linearizar uma lista de inteiros. Dica: use o predicado concatenar.
Ex.: ?- linearizar([[1,2,3], [4,5], [6], [7,8]], L).
L = [1, 2, 3, 4, 5, 6, 7, 8].
*/

linearizar([], []).
linearizar([N|L], LR) :- concatenar(N, LM, LR), linearizar(L, LM).

concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).