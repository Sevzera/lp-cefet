/*
7) Gerar uma lista com os elementos de uma faixa (inclusive).
Ex.: ?- gerar(5, 10, L).
L = [5, 6, 7, 8, 9, 10].
*/

gerar(FINAL, FINAL, [FINAL]).
gerar(PRIMEIRO, FINAL, [PRIMEIRO|L]) :- N is PRIMEIRO + 1, gerar(N, FINAL, L).