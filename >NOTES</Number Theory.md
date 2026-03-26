# Fermat’s Little Theorem

- if p is prime
    - (a^n) % p = (a^(n%(p-1))) % p;
    - (1/a) % p = (a^(p-2)) % p;
    - a % p != 0, then : (a ^ (p-1)) % p = 1;

---

# Modular Arithmetic

- (A + B) % M = ((A % M) + (B % M)) % M;
- (A * B) % M = ((A % M) * (B % M)) % M;
- (A - B) % M = ((A % M) - (B % M) + M) % M;
- (A / B) % M = ((A % M) * ((B^-1) % M)) % M;

---

# Euler’s Totient Related

- φ(n) = n ∏ (1 - 1/Pi)  [from i = 1, 2, .., k and Pi: distinct prime factors of n];

- from 1 to N the count of numbers for which GCD(x, N) = d is: φ(N / d);

- Sum of Co-primes of N = (φ(N) / 2) * N;

- if n = (p^k): φ(p^k) = (p^k) - p^(k-1);

- for the divisors of N, d:
    - ∑ φ(d) = N   [for d | N];
    - ∑ GCD(i, N) = ∑ d * (φ / d)   [from i = 1, ..., N];

- if GCD(a, n) = 1, then:
    - (1 / a) % n = a^(φ(n) - 1) % n;
    - φ(a * n) = φ(a) * φ(n);

---

# Others

- if (a - b) % m = 0 then: a % m = b % m;

- Product of divisors of N = N^(NOD / 2);

- if a = ∏(Pi^ei), b = ∏(Pi^fi) and ∏(Pi^(ei % 2)) = ∏(Pi^(fi % 2)) then: a * b is a perfect square;
