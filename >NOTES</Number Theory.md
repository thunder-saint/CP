# Fermat’s Little Theorem

- if p is prime and a % p != 0 :
    - (a^n) % p = (a^(n%(p-1))) % p;
    - (1/a) % p = (a^(p-2)) % p;
    - (a ^ (p-1)) % p = 1;

---

# Modular Arithmetic

- (A + B) % M = ((A % M) + (B % M)) % M;
- (A * B) % M = ((A % M) * (B % M)) % M;
- (A - B) % M = ((A % M) - (B % M) + M) % M;
- (A / B) % M = ((A % M) * ((B^-1) % M)) % M;
- if (a - b) % m = 0 then: a % m = b % m;
- n % x retunrs n or p < (n +1) / 2;
---

# Conjectures:

- every even integer n>2 can be written as the sum of two primes;
  
- there is always at least 1 prime between n^2 and (n+1)^2 for any integer n>=1;
  
---

# Prime Divisors Related

- the number of positive divisors of 𝑝^𝑒 that are divisible by 𝑝^𝑎 is: e - a + 1

- Product of divisors of N = N^(NOD / 2);

- if a = ∏(Pi^ei), b = ∏(Pi^fi) and ∏(Pi^(ei % 2)) = ∏(Pi^(fi % 2)) then: a * b is a perfect square;

---

# Euler’s Totient Related

- φ(n) = n ∏ (1 - 1/Pi)  [from i = 1, 2, .., k and Pi: distinct prime factors of n];

- from 1 to N the count of numbers for which GCD(x, N) = d is: φ(N / d);

- Sum of Co-primes of N = (φ(N) / 2) * N;

- if n = (p^k): φ(p^k) = (p^k) - p^(k-1);

- for the divisors of N, d:
    - ∑ φ(d) = N   [for d | N];
    - ∑ GCD(i, N) = ∑ d * φ(N / d)   [from i = 1, ..., N];

- if GCD(a, n) = 1, then:
    - (1 / a) % n = a^(φ(n) - 1) % n;
    - φ(a * n) = φ(a) * φ(n);
    - (a^(φ(n))) % n = 1;

---

# Mobius Function
- Counting Pairs with gcd(x,y)=k  ∑ μ(d)⌊N / kd​⌋⌊M / kd​ ⌋ d = 1 ... min(n/d, m/d)
- Counting Coprime k-tuples ∑​ μ(d)⌊n / d​⌋^k.
- Number of squarefree integers ≤N:  ∑μ(i)⌊N / i^2] , i upto sqrt(n)
​
---


# Random Theorem
- for two positive integers a and b where GCD(a, b) = 1 (using only addition / non-negative multipliers):
    - largest Impossible Sum: ab - a - b
    - total Number of Impossible Sums: (a - 1)(b - 1) / 2;
