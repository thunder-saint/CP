const int N = 1e7 + 1;
int f[N], invf[N];
void pre() {
    f[0] = 1;
    for(int i = 1; i < N; i++) f[i] = 1LL * i * f[i-1] % MOD;
    invf[N-1] = power(f[N-1], MOD - 2, MOD);
    for(int i = N - 2; i >= 0; i--) invf[i] = 1LL * invf[i+1] * (i+1) % MOD;
}

int  nPr(int n, int r) {
    if(n < r || n < 0 || r < 0) return 0;
    return 1LL * f[n] * invf[n-r] % MOD;
}

int nCr(int n, int r) {
    if(n < r || n < 0 || r < 0) return 0;
    return 1LL * f[n] * invf[r] % MOD * invf[n-r] % MOD;
}
