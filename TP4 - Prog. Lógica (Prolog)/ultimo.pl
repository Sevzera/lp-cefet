/*
5) Obter o último elemento de uma lista.
Ex.: ?- ultimo([1, 2, 3, 4], U).
U = 4.
*/

ultimo([X], X).
ultimo([N|L], ULTIMO) :- ultimo(L, ULTIMO).