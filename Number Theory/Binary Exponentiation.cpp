int power(int x, int n, int MOD) { 
    int ans = 1 % MOD;
    x %= MOD;
    if (x < 0) x += MOD;
    while (n) {
        if (n & 1) ans = (int)((__int128)ans * x % MOD); 
        x = (int)((__int128)x * x % MOD);
        n >>= 1; 
    }
    return ans;
}
int Inverse(int n, int MOD) {
    n %= MOD;
    if (n < 0) n += MOD;
    if (n == 0) return -1;
    return power(n, MOD - 2, MOD);
}
