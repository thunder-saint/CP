struct BinaryLifting {
    void build(int n) {
        for (int i = 1; i < LOG; i++) {
            for (int u = 1; u <= n; u++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
    }
    bool ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != 0 && !ancestor(up[u][i], v)) 
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    int kth(int u, int k) {
        for (int i = 0; i < LOG; i++) {
            if ((k >> i) & 1) u = up[u][i];
            if (u == 0) return 0;
        }
        return u;
    }
    int k_node(int u, int v, int k) {
        k--;
        int l = lca(u, v);
        int d = depth[u] + depth[v] - (depth[l] << 1);
        if (k > d) return -1; 
        if (depth[l] + k <= depth[u]) return kth(u, k);
        k -= depth[u] - depth[l];
        return kth(v, depth[v] - depth[l] - k);
    }
};
