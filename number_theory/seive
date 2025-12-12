const int MAX_N = 100000000; 
bitset<MAX_N + 1> prime;
vector <int> p;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= MAX_N; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAX_N; i += p) {
                prime[i] = 0;
            }
        }
    }
    for(int i=2; i< MAX_N; i++) {
     if(prime[i]) p.push_back(i);
    }
}
