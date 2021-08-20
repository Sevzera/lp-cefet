/*
3) Obter o valor médio de uma lista de inteiros.
Ex.: ?- medio([4, 5, 2, 3, 1], M).
M = 3.0.
*/

medio([N|L], MEDIO) :- nelementos([N|L], TAMANHO), soma([N|L], SOMA), MEDIO is SOMA / TAMANHO.

soma([], 0).
soma([N|L], S) :- soma(L, PROXIMO), S is N + PROXIMO.

nelementos([], 0).
nelementos([_|L], TAMANHO) :- nelementos(L, CONT), TAMANHO is CONT + 1.