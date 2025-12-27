/*
Sedam stabala poredano je u krug. Stabla su napali nametnici i otpada im lišće.
Svaki dan sa stabla otpadne neka količina lišća. Količina lišća koja će sa
stabla x otpasti sutra ovisi o tome koliko je danas lišća palo s tog stabla,
stabla lijevo od njega i stabla desno od njega, po sljedećoj relaciji:

sutra[x] = 3 * danas[x- 1] + danas[x] + 2 * danas[x + 1]

Pritom je stablo x-1 lijevo od stabla x. Lijevo od 0 je 6, a desno od 6 je 0.
Ulazni podaci su n (1 <= n <= 10^9) i zatim sedam brojeva koji predstavljaju
redom količine lišća koje otpadnu s pojedinog stabla prvi dan. Treba ispisati
koliko lišća će pas s pojedinog stabla n-ti dan. (Ispisati ostatak pri
dijeljenju rješenja s 1000000.)

Ispis:
3153 2984 2789 3011 2689 3201 2909
*/
