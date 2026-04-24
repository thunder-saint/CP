struct DSU {
    vector<int> pars, sz, parr, rnk;
    int components;
    DSU(int n) {
        components = n;
        pars.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(pars.begin(), pars.end(), 0);

        parr.resize(n + 1);
        rnk.assign(n + 1, 0);
        iota(parr.begin(), parr.end(), 0);
    }
    int finds(int x) {
        while (x != pars[x]) {
            pars[x] = pars[pars[x]]; 
            x = pars[x];
        }
        return x;
    }
    void unions(int u, int v) {
        int ru = finds(u), rv = finds(v);
        if (ru == rv) return;
        if (sz[ru] < sz[rv]) swap(ru, rv);
        pars[rv] = ru;
        sz[ru] += sz[rv];
        components--;
    }

    int findr(int x) {
        while (x != parr[x]) {
            parr[x] = parr[parr[x]]; 
            x = parr[x];
        }
        return x;
    }
    void unionr(int u, int v) {
        int ru = findr(u), rv = findr(v);
        if (ru == rv) return;
        if (rnk[ru] < rnk[rv]) swap(ru, rv);
        if (rnk[ru] == rnk[rv]) rnk[ru]++;
        parr[rv] = ru;
        components--;
    }
};
