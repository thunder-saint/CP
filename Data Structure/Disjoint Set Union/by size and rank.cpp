struct DSU {
    vector<int> p, sz, mn, mx; 
    int components;
    DSU(int n) {
        components = n;
        p.resize(n + 1), sz.assign(n + 1, 1);
        mn.resize(n + 1), mx.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            p[i] = mn[i] = mx[i] = i;
        }
    }
    int find(int x) {
        while (x != p[x]) {
            p[x] = p[p[x]], x = p[x];
        }
        return x;
    }
    void Union (int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) return;
        components--;
        if (sz[ru] < sz[rv]) swap(ru, rv);
        p[rv] = ru, sz[ru] += sz[rv];
        mn[ru] = min(mn[ru], mn[rv]);
        mx[ru] = max(mx[ru], mx[rv]);
    }
};
