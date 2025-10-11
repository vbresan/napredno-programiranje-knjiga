/*

Tvornica pravokutnog oblika sastoji se od n (1 <= n <= 1000) redova i m 
(1 <= m <= 1000) stupaca. Ukupno n * m dijelova. Svaki dio tvornice ima 
zidove s nekih strana. Unosi se n i m i zatim n redova od po m brojeva. 
Svaki broj od 0 do 15 opisuje jedan dio tvornice. Binarni zapis broja 
opisuje s kojih strana tog dijela tvornice se nalaze zidovi. Ako je dan 
npr. broj 10, onda je njegov binarni zapis 1010, što znači da ima zid sa 
sjevera, nema s istoka, ima s juga i nema sa zapada. Opis će biti takav 
da tvornica ima zidove s vanjske strane. Ispiši za svaku prostoriju njenu 
veličinu. Ispiši prostorije od veće prema manjoj.

Ako je tvornica opisana sa:
9 14 11 12 13
5 15 11  6  7
5  9 14  9 14
3  2 14  3 14

onda je u pitanju izgled:

┌─────────┬─────────┬────┐
│1001 1110│1011 1100│1101│
│    ┌────┼────     │    │
│0101│1111│1011 0110│0111│
│    ├────┴────┬────┴────┤
│0101│1001 1110│1001 1110│
│          ────┤     ────┤
│0011 0010 1110│0011 1110│
└──────────────┴─────────┘


out: 9 4 4 2 1

*/

