const int MAX_N = 100000000; 
bitset<MAX_N + 1> prime;
vector <int> p;
void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = 0;
            }
        }
    }
    for(int i=2; i< MAX_N; i++) {
     if(prime[i]) p.push_back(i);
    }
}
