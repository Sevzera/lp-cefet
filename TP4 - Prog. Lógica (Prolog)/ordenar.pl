/*
15) Ordenar uma lista de inteiros.
Ex.: ?- ordenar([3, 1, 2], L).
L = [1, 2, 3].
*/

ordenar([], []).
ordenar([X|L], LR) :- menor(X, L, LFT), maior(X, L, RGT), ordenar(LFT, LFTS), ordenar(RGT, RGTS), concatenar(LFTS, [X], LC), concatenar(LC, RGTS, LR).

menor(_, [], []).
menor(N, [X|L], [X|R]) :- N >= X, menor(N, L, R).
menor(N, [X|L], R) :- N < X, menor(N, L, R).

maior(_, [], []).
maior(N, [X|L], [X|R]) :- N < X, maior(N, L, R).
maior(N, [X|L], R) :- N >= X, maior(N, L, R).

concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).