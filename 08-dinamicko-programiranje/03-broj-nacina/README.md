## 8.3.1. Modularna aritmetika

Zbrajanje: `(a%x + b%x)%x == (a + b)%x`  

Oduzimanje: `(a%x - b%x)%x == (a - b)%x`  

Prebacivanje negativnog `a%b` u pozitivan ostatak: `(a%b + b)%b`  

Mnozenje: `(a%x * b%x)%x == (a * b)%x`  

Dijeljenje: `(a / b)%x == (a * b^(x-2))%x`  
Pritom `a` treba biti djeljiv s `b`, `b` ne smije biti visekratnik od `x`, 
a `x` mora biti prosti broj.


