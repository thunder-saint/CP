const int32_t MX = 1e8, N = 1e7;
bitset<MX + 1> isprime;
int32_t spf[N + 1], phi[N + 1];
int32_t div[N + 1], pw[N + 1];
int8_t mu[N + 1];
vector<int32_t> primes;
void sieve() {
    primes.reserve(5761455); 
    isprime.set(), phi[1] = mu[1] = div[1] = 1;
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= MX; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            if (i <= N) {
                spf[i] = i, phi[i] = i - 1;
                mu[i] = -1, div[i] = 2, pw[i] = 1;
            }
        }
        for (int j = 0; j < primes.size(); j++) {
            int nxt = i * primes[j]; 
            if (nxt > MX) break;
            isprime[nxt] = 0;
            if (nxt <= N) {
                spf[nxt] = primes[j];
               if (i % primes[j] == 0) {
                    phi[nxt] = phi[i] * primes[j];
                    mu[nxt] = 0, pw[nxt] = pw[i] + 1;
                    div[nxt] = div[i] / (pw[i] + 1) * (pw[i] + 2);
                } 
                else {
                    phi[nxt] = phi[i] * (primes[j] - 1);
                    mu[nxt] = -mu[i], pw[nxt] = 1; 
                    div[nxt] = div[i] * 2;
                }
            }
            if (i % primes[j] == 0) break;
        }
    }
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
