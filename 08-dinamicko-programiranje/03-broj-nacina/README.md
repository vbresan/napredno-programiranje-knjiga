## 8.3.1. Modularna aritmetika

Zbrajanje: `(a % x + b % x) % x == (a + b) % x`  

Oduzimanje: `(a % x - b % x) % x == (a - b) % x`  

Prebacivanje negativnog `a % b` u pozitivan ostatak: `(a % b + b) % b`  

Mnozenje: `(a % x * b % x) % x == (a * b) % x`  

Dijeljenje: `(a / b) % x == (a * b ^ (x - 2)) % x`  
Pritom `a` treba biti djeljiv s `b`, `b` ne smije biti visekratnik od `x`, 
a `x` mora biti prosti broj.  

`(a / b) % x == (a * pow(b, x - 2, x)) % x`

```
long long pow(long long base, int n, int x) {  // (base ^ n) % x
    long long result = 1;
    while (n) {
        if (n & 1) {
            result = (result * base) % x;
        }
        base = (base * base) % x;
        n >>= 1;
    }
    return result;
}
```

