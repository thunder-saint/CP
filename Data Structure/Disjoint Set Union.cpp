struct DSU {
    vector<int> p, sz, mn, mx, xp, nxt, dist; 
    int components, M = 1;
    DSU(int n) {
        components = n; 
        p.resize(n + 2), sz.assign(n + 2, 1);
        mn.resize(n + 2), mx.resize(n + 2);
        xp.assign(n + 2, 0), nxt.resize(n + 2); 
        dist.assign(n + 2, 0);
        for(int i = 0; i <= n + 1; i++) {
            p[i] = mn[i] = mx[i] = nxt[i] = i;
        }
    }
    int find(int x) {
        while (x != p[x]) {
            if (p[x] != p[p[x]]) {
                xp[x] += xp[p[x]];
                dist[x] += dist[p[x]];
                // add here;
            }
            p[x] = p[p[x]], x = p[x];      
        }
        return x;
    }
    int find_nxt(int x) {
        while (x != nxt[x]) {
            nxt[x] = nxt[nxt[x]], x = nxt[x];
        }
        return x;
    }
    void Union(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) return;
        components--;
        if (sz[ru] < sz[rv]) swap(ru, rv);
        p[rv] = ru, sz[ru] += sz[rv];
        mn[ru] = min(mn[ru], mn[rv]);
        mx[ru] = max(mx[ru], mx[rv]);
        xp[rv] -= xp[ru]; 
         // add here;
        M = max(M, (long long)sz[ru]);
    }
    void union_directed(int subordinate, int boss) {
        int root_sub = find(subordinate);
        int root_boss = find(boss);
        if (root_sub != root_boss) {
            components--; 
            p[root_sub] = root_boss;
            dist[root_sub] = 1;
            sz[root_boss] += sz[root_sub];
            mn[root_boss] = min(mn[root_boss], mn[root_sub]);
            mx[root_boss] = max(mx[root_boss], mx[root_sub]);
            xp[root_sub] -= xp[root_boss]; 
            M = max(M, sz[root_boss]);
        }
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
    // get what ever you want
    // int get(int x) {
    //     find(x); 
    //     int total = 0;
    //     while (x != p[x]) total += any[x], x = p[x];
    //     return total + any[x];
    //     [any = xp, dist, col;]
    // }

};
