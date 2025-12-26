/*
Subota je, pa su Kova i Kuso, kao i svake subote, krenuli u obilazak kafića.
Kafići se nalaze u dugačkoj ulici koja se proteže od zapada prema istoku. Kova i
Kuso kreću iz početnog kafića koji je najzapadniji u ulici. Kafiće obilaze tako
da se prvo kreću samo prema istoku sve do najistočnijeg kafića i vraćaju se samo
prema zapadu do početnog, najzapadnijeg kafića. Cilj im je ući u što više
kafića, tako da u niti jedan, osim početnog, ne uđu dvaput. Kova i Kuso za svaki
kafić imaju omiljeno piće koje uvijek piju u tom kafiću. Problem je u tome što
ne mogu nakon svakog kafića ući u bilo koji drugi, jer bi se od nekih
kombinacija uzastopnih pića, koja ne idu zajedno, osjećali loše i uništili si
večer. Ulazni podaci se sastoje od broja n (1 <= n <= 400) i m (1 <= m <= 2500).
n je broj kafića, a m je broj različitih veza koje opisuju iz kojeg u koji kafić
se može ići. Slijedi m parova brojeva a i b (0 <= a,b < n) koji opisuju da se iz
kafića a može otići u kafić b (ne i obratno). Za svaki par kafića x i y, ako je
x < y, vrijedi da je kafić x zapadnije od kafića y. Kafić 0 je najzapadniji, a
kafić n-1 je najistočniji. Ispišite koliko najviše kafića Kova i Kuso mogu
posjetiti (početni kafić se broji samo jednom). Ulaz će biti takav da će se
uvijek moći otići do najistočnijeg kafica i natrag.

Ispis: 9
*/
