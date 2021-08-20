/*
11) Compactar uma lista de elementos consecutivos.
Ex.: ?- compactar([a,a,a,a,b,c,c,a,a,d,e,e,e,e], L).
L = [[4,a], [1,b], [2,c], [2,a], [1,d], [4,e]].
*/

compactar([],[]).
compactar([N|L], [[OCRR, N]|LM]) :- avancar(N, L, CONT, LR), compactar(LR, LM), OCRR is CONT + 1.

avancar(_, [], 0, []).
avancar(N1, [N2|L], 0, [N2|L]) :- N1 \== N2.
avancar(N1, [N1|L], I, LR) :- avancar(N1, L, CONT, LR), I is CONT + 1.