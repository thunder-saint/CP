struct DSU {
    vector<int> p, sz, add, dist, col, nxt, mn, mx;
    int components;
    DSU(int n) {
        components = n;
        p.resize(n + 2); sz.assign(n + 2, 1);
        dist.assign(n + 2, 0); col.assign(n + 2, 0);
        add.assign(n + 2, 0); nxt.resize(n + 2);
        mn.resize(n + 2); mx.resize(n + 2);
        for (int i = 0; i <= n + 1; i++) {
            p[i] = nxt[i] = mn[i] = mx[i] = i;
        }
    }
    int find(int x) {
        while (x != p[x]) {
            if (p[x] != p[p[x]]) {
                dist[x] += dist[p[x]];
                col[x]  ^= col[p[x]];
                add[x]  += add[p[x]];
            }
            p[x] = p[p[x]], x = p[x];
        }
        return x;
    }
    tuple<int, int, long long> getVal(int x) {
        find(x);
        int tCol = 0, tDist = 0; long long tAdd = 0;
        while (x != p[x]) {
            tCol  ^= col[x];
            tDist += dist[x];
            tAdd  += add[x];
            x = p[x];
        }
        tAdd += add[x];
        return {tCol, tDist, tAdd};
    }
    void Union(int u, int v, bool dir = false, int w = 1) {
        auto [cu, du, au] = getVal(u);
        auto [cv, dv, av] = getVal(v);
        int ru = find(u), rv = find(v);
        if (ru == rv) return;
        if (!dir && sz[ru] > sz[rv]) swap(ru, rv), swap(du, dv);
        p[ru] = rv, sz[rv] += sz[ru];
        add[ru] -= add[rv];
        if (dir) dist[ru] = w;
        else dist[ru] = w + dv - du;
        col[ru] = 1 ^ cu ^ cv;
        mn[rv] = min(mn[rv], mn[ru]);
        mx[rv] = max(mx[rv], mx[ru]);
        components--;
    }
    int find_nxt(int x) {
        while (x != nxt[x]) nxt[x] = nxt[nxt[x]], x = nxt[x];
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
