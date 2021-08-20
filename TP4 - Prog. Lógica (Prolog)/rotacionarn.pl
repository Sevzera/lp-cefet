/*
14) Rotacionar uma lista n posições.
Ex.: ?- rotacionarn(2, [1, 2, 3, 4, 5], L).
L = [3, 4, 5, 1, 2].
*/

rotacionarn(0, L, L).
rotacionarn(_, [], []).
rotacionarn(RTC, [N|L], LR) :- RTCCONT is RTC - 1, concatenar(L, [N], LM), rotacionarn(RTCCONT, LM, LR).

concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).