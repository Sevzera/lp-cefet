/*
12) Remover de uma lista um elemento (todas as suas ocorrências).
Ex.: ?- remover(3, [1,3,2,3,4], L).
L = [1, 2, 4].
*/

remover(_, [], []).
remover(N1, [N1|L], LR) :- remover(N1, L, LR).
remover(N1, [N2|L], [N2|LR]) :- N1 \== N2, remover(N1, L, LR).