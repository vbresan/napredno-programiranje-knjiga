/*
Ulazni podatak je n (2 <= n <= 10^9). Ispiši ostatak pri djeljenju n-tog
Fibonaccijevog brojas 1000000. F[0]=0, F[1]=1, F[n]=F[n-1]+F[n-2].

F = [[0 1],
     [1 1]]

M1 = [[0],
      [1]]

F4 = F * M3 = F * F * M2 = F * F * F * M1= F^3 * M1.
F^150 = F^128 * F^16 * F^4 * F^2
*/
