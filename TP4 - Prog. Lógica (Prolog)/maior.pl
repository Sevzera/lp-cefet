/*
2) Obter o maior valor de uma lista de inteiros.
Ex.: ?- maior([4, 5, 2, 3, 1], M).
M = 5.
*/

maior([N], N).
maior([N|L], MAIOR) :- maior(L, MAIOR), MAIOR >= N.
maior([N|L], N) :- maior(L, MAIOR), N > MAIOR.