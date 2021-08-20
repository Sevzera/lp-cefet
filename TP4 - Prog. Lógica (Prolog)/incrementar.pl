/*
9) Incrementar em uma unidade cada elemento de uma lista de inteiros.
Ex.: ?- incrementar([5, 6, 7, 8], L).
L = [6, 7, 8, 9] .
*/

incrementar([], []).
incrementar([N|L], [NINC|LINC]) :- incrementar(L, LINC), NINC is N + 1. 