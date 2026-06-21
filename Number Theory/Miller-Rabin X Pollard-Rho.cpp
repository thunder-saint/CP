#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __int128_t;
u64 pow_mod(u64 x, u64 n, u64 m) {
    u64 res = 1;
    for (; n; n >>= 1, x = (u128)x * x % m)
        if (n & 1) res = (u128)res * x % m;
    return res;
}
bool miller_rabin(u64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    u64 d = n - 1; int s = 0;
    while (!(d & 1)) d >>= 1, s++;
    static const u64 bases[] = {
        2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (u64 a : bases) {
        if (n <= a) break;
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}
u64 pollard_rho(u64 n) {
    static const int small_primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int p : small_primes) {
        if (n % p == 0) return p;
    }
    if (miller_rabin(n)) return n;
    u64 x = 0, y = 0, c = 1, u = 1, v = 1, d = 1;
    auto f = [&](u64 val) { return (u64)(((u128)val * val + c) % n); };
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (d == 1) {
        x = y = rng() % (n - 2) + 2;
        c = rng() % (n - 1) + 1;
        u = 1; int t = 0;
        while (d == 1) {
            x = f(x); y = f(f(y));
            v = u;
            u = (u128)u * (x > y ? x - y : y - x) % n;
            if (u == 0) { d = std::gcd(v, n); break; }
            if (++t == 32) { 
                t = 0; d = std::gcd(u, n);
                if (d > 1) break;
            }
        }
        if (d == n) d = 1; 
    }
    return d;
}
void factorize(u64 n, vector<u64>& res) {
    if (n == 1) return;
    if (miller_rabin(n)) { res.push_back(n); return; }
    u64 d = pollard_rho(n);
    factorize(d, res);
    factorize(n / d, res);
}
