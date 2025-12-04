   vector<bool> prime (int n) {
       vector<bool> isPrime(n+1,true);
       isPrime[0]=isPrime[1]=false;
       for(int i=2; i*i<=n; i++) {
           if(isPrime[i]) {
               for(int j=i*i; j<=n; j+=i) isPrime[j]=false;
           }
       }
       return isPrime;
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
