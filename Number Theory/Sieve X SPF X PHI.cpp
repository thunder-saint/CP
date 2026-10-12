const int N = 1e7+1;
bitset<N + 1> prime;
vector <int> primes;
int32_t spf[N], phi[N];
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p < N; p++) {
        if (prime[p]) {
            for (int i = p * p; i < N; i += p) {
                prime[i] = 0;
                spf[i] = min(spf[i], p);
            }
        }
    }
    for(int i=2; i < N; i++) {
        if(prime[i]) primes.push_back(i);
    }
}
int PHI() {
    phi[1] = 1;
    for (int i = 2; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int euler_totient(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
tuple<int,int, int> nod_sod_phi(int n) {
    int nod = 1, sod = 1, coprime = n;
    while (n > 1) {
        int p = spf[n], cnt = 0;
        coprime -= coprime / p;
        int curr = 1, f = 1;
        while (n % p == 0) {
            cnt++; f *= p, curr += f, 
            n /= p;
        }
        nod *= (cnt + 1);
        sod *= curr;
    }
    return {nod, sod, coprime};
}
vector <int> segmented_sieve(int l, int r) {
    if(l == 1) l++;
    int lmt = sqrt(r);
    while(lmt * lmt <= r) lmt++;
    while(lmt * lmt > r) lmt--;
    vector <int> v;
    vector <bool> isPrime(r - l + 1, true);
    for(auto &a : primes) {
        if(a > lmt) break;
        int start = max((int)a * a, ((l + a - 1) / a) * a);
        for(int i = start; i <= r; i += a) isPrime[i - l] = false;
    }
    for(int i = l; i <= r; i++) {
        if(isPrime[i - l]) v.push_back(i);
    }
    return v;
}
