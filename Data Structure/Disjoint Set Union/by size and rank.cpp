struct DSU {
    vector<int> par, sz, rnk;
    int components;
    DSU(int n) {
        components = n;
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
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
        par[rv] = ru;
        sz[ru] += sz[rv];
        
        // by rank
        // if (rnk[ru] < rnk[rv]) swap(ru, rv);
        // if (rnk[ru] == rnk[rv]) rnk[ru]++;
        // par[rv] = ru;
    }

};
