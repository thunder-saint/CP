struct DSU {
    vector<int> p, sz, mn, mx, xp, nxt; 
    int components, M = LLONG_MIN;
    DSU(int n) {
        components = n;
        p.resize(n + 1), sz.assign(n + 1, 1);
        mn.resize(n + 1), mx.resize(n + 1);
        xp.assign(n + 1, 0), nxt.resize(n + 2); 
        for(int i = 0; i <= n; i++) {
            p[i] = mn[i] = mx[i] = nxt[i] = i;
        }
        nxt[n + 1] = n + 1;
    }
    int find(int x) {
        while (x != p[x]) {
            if (p[x] != p[p[x]]) {
                xp[x] += xp[p[x]];
            }
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
        xp[rv] -= xp[ru]; 
        M = max(M, sz[ru]);
    }
    int get_xp(int x) {
        int total = 0;
        while (x != p[x]) {
            total += xp[x], x = p[x];
        }
        total += xp[x];
        return total;
    }
    int find_nxt(int x) {
        while (x != nxt[x]) {
            nxt[x] = nxt[nxt[x]], x = nxt[x];
        }
        return x;
    }
    void union_range(int L, int R) {
        if (L > R) swap(L, R);
        int curr = find_nxt(L); 
        while (curr < R) {
            int next_node = find_nxt(curr + 1); 
            Union(curr, next_node);
            nxt[curr] = next_node; 
            curr = next_node;
        }
    }
};
