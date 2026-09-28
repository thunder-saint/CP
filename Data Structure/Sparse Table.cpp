struct SparseTable {
    vector<vector<int>> t;
    int n, L; // Added 'n' here
    SparseTable(int n) : n(n) { // Save 'n'
        L = 32 - __builtin_clz(n);
        t.assign(L, vector<int>(n + 1));
    }
    void build(int a[]) {
        for (int i = 1; i <= n; ++i) t[0][i] = a[i];
        for (int k = 1; k < L; ++k) {
            int x = (1 << (k - 1)), y = (1 << k);
            for (int i = 1; i + y - 1 <= n; ++i) {
                t[k][i] = min(t[k - 1][i], t[k - 1][i + x]); // change
            }
        }
    }
    int query(int l, int r) const {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(t[k][l], t[k][r - (1 << k) + 1]); // change
    }
};
