// path query: dist from root to node
const int N = 1e5 + 1;
vector<int> g[N];
bool vis[2 * N];
int tin[2 *N], tout[2 * N], weight[N];
int timer = 0;
void dfs(int u, int p) {
    tin[u] = ++timer;
    vis[u] = true;
   // a[tin[u]] = edge_w;
    for (auto &v : g[u]) {
        if (v == p) continue;
        if (!vis[v]) {
           // weight[v] = w;
            dfs(v, u);
        }
    }    
    tout[u] = ++timer;
    // a[tout[u]] = -edge_w;
}


// lca O(1); full visit
vector<int> g[N];
int depth[N];
int euler_tour[2 * N], euler_depth[2 * N];
int tin[N];
int timer = 0;
void dfs(int u, int p = 0) {
    tin[u] = ++timer;
    euler_tour[timer] = u;
    euler_depth[timer] = depth[u];
    for (int v : g[u]) {
        if (v == p) continue; 
        depth[v] = depth[u] + 1;
        dfs(v, u);
        ++timer;
        euler_tour[timer] = u;
        euler_depth[timer] = depth[u];
    }
}
struct SparseTable {
    vector<vector<int>> t;
    int n, L;
    SparseTable(int n) : n(n) {
        L = 32 - __builtin_clz(n);
        t.assign(L, vector<int>(n + 1));
    }
    void build() {
        for (int i = 1; i <= n; ++i) t[0][i] = i; 
        for (int k = 1; k < L; ++k) {
            int x = (1 << (k - 1)), y = (1 << k);
            for (int i = 1; i + y - 1 <= n; ++i) {
                int l = t[k - 1][i], r = t[k - 1][i + x];
                t[k][i] = (euler_depth[l] < euler_depth[r]) ? l : r;
            }
        }
    } 
    int query(int ql, int qr) const {
        int k = 31 - __builtin_clz(qr - ql + 1);
        int l = t[k][ql];
        int r = t[k][qr - (1 << k) + 1];
        return (euler_depth[l] < euler_depth[r]) ? l: r;
    }
    int get_lca(int u, int v) {
        int l = tin[u], r = tin[v];
        if (l > r) swap(l, r);
        return euler_tour[query(l, r)]; 
    }
};
