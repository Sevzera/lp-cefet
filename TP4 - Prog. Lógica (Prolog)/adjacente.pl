/*
6) Verificar se um elemento X é adjacente a um elemento Y.
Ex.: ?- adjacente(3, 4, [1, 2, 3, 4, 5, 6]).
True.
*/

adjacente(X, Y, [X, Y|_]).
adjacente(X, Y, [N1, N2|L]) :- N1 \== X, N2 \== Y, adjacente(X, Y, [N2|L]).