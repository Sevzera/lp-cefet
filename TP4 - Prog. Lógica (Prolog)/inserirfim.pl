/*
4) Inserir um elemento no fim da lista.
Ex.: ?- inserirfim(4, [1, 2, 3], L).
L = [1,2,3,4].
*/

inserirfim(FIM, [], [FIM]).
inserirfim(FIM, [N|L], [N|LR]) :- inserirfim(FIM, L, LR).