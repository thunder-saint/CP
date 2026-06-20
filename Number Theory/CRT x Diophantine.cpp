int inv[1000001];
int extGCD(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        x -= q * x1; swap(x, x1);
        y -= q * y1; swap(y, y1);
        a1 -= q * b1; swap(a1, b1);
    }
    return a1;
}
int modInverse(int a, int m) {
    int x, y;
    int g = extGCD(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m; 
}
pair<int, int> CRT(const vector<int>& a, const vector<int>& m) {
    if (a.empty()) return {-1, -1};
    int a1 = a[0], m1 = m[0], sz = a.size();
    for (int i = 1; i < sz; i++) {
        int a2 = a[i], m2 = m[i], x, y;
        int g = extGCD(m1, m2, x, y);
        if ((a2 - a1) % g != 0) return {-1, -1};
        int md = m2 / g, diff = (a2 - a1) / g;
        diff = (diff % md + md) % md; 
        x = (x % md + md) % md; 
        int t = ((__int128_t)diff * x) % md;
        a1 = a1 + (int)((__int128_t)t * m1); 
        m1 = m1 * md;
        a1 = (a1 % m1 + m1) % m1;
    }
    return {a1, m1};
}
void invs(int mod) {
    inv[0] = 0, inv[1] = 1;
    for(int i = 2; i <= 1000000; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod; 
    } 
}
bool Diophantine(int a, int b, int c, int &x0, int &y0, int &g) {
    g = extGCD(abs(a), abs(b), x0, y0);
    if (c % g != 0) return false;
    x0 *= c / g, y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
