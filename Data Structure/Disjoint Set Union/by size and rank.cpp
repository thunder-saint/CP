struct DSU {
    vector<int> par, sz, rnk, mn, mx; 
    int components;
    DSU(int n) {
        components = n;
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        mn.resize(n + 1);
        mx.resize(n + 1);
        iota(all(par), 0);
        iota(all(mn), 0);
        iota(all(mx), 0); 
        rnk.assign(n + 1, 0);
    }

    int find(int x) {
        while (x != par[x]) {
            par[x] = par[par[x]]; 
            x = par[x];
        }
        return x;
    }

    void Union (int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) return;
        components--;
        // by size
        if (sz[ru] < sz[rv]) swap(ru, rv);
        par[rv] = ru, sz[ru] += sz[rv];
        mn[ru] = min(mn[ru], mn[rv]);
        mx[ru] = max(mx[ru], mx[rv]);
        // by rank
        // if (rnk[ru] < rnk[rv]) swap(ru, rv);
        // if (rnk[ru] == rnk[rv]) rnk[ru]++;
        // par[rv] = ru;
    }
};
