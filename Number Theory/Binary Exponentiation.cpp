int Mod(int val, int m, bool eular = false) {
    if (!eular) {
        int res = val % m;
        return res < 0 ? res + m : res; 
    }
    return val < m ? val : (val % m) + m; 
}

int power(int x, int n, int m, bool eular = false) { 
    int ans = Mod(1, m, eular);
    x = Mod(x, m, eular); 
    while (n) {
        if (n & 1) ans = Mod((int)((__int128)ans * x), m, eular); 
        x = Mod((int)((__int128)x * x), m, eular);
        n >>= 1; 
    }
    return ans;
}
int Inverse(int n, int MOD) {
    n = Mod(n, MOD, false);
    if (n == 0) return -1;       
    return power(n, MOD - 2, MOD); 
}
vector <int> a, pre;
int tower(int l, int r, int i) {
    if(l == r) return Mod(a[l], pre[i], true);
    if(pre[i] == 1) return 1;
    return power(a[l], tower(l + 1, r, i + 1), pre[i], true);
    // pre are phis, in solve print with mod pre[0];
}
