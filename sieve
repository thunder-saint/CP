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



//SPF: 

const int N = 1e7+1;
int spf[N];
void SPF() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}




//phi:

const int N = 1e5 + 9;
int phi[N];
void totient() {
  for (int i = 1; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
    }
  }
}
