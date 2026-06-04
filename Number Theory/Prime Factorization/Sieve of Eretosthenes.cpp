const int MAX_N = 100000000; 
bitset<MAX_N + 1> prime;
vector <int> p;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) prime[j] = 0;
        }
    }
    p.push_back(2);
    for(int i=3; i<= MAX_N; i+=2) {
     if(prime[i]) p.push_back(i);
    }
}
vector <int> segmented_sieve(int l, int r) {
    if(l == 1) l++;
    int lmt = sqrt(r);
    while(lmt * lmt <= r) lmt++;
    while(lmt * lmt > r) lmt--;
    vector <int> v;
    vector <bool> isPrime(r - l + 1, true);
    for(auto &a : p) {
        if(a > lmt) break;
        int start = max(a * a, ((l + a - 1) / a) * a);
        for(int i = start; i <= r; i += a) isPrime[i - l] = false;
    }
    for(int i = l; i <= r; i++) {
        if(isPrime[i - l]) v.push_back(i);
    }
    return v;
}
