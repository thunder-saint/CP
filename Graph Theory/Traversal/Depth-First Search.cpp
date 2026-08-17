const int N = 1e5 + 1;
const int LOG = 31;
vector<int> g[N], stk;
vector<pair<int, int>> edge_stk;
vector<vector<int>> comps, bccs;
int up[N][LOG], par[N];
bool vis[N], leaf[N], in_stk[N], cutpoint[N];
int depth[N], subtree_sz[N], height[N];
int tin[N], tout[N], flat_tree[N];
int low[N], comp_id[N];
int timer = 0, comp_cnt = 0, bcc_cnt = 0;
void dfs(int u, int p) {
    tin[u] = low[u] = ++timer;
    flat_tree[timer] = u;
    height[u] = 0, subtree_sz[u] = 1;
    par[u] = up[u][0] = p;
    vis[u] = leaf[u] = in_stk[u] = true;
    stk.push_back(u);
    int child = 0; 
    for (auto &v : g[u]) {
        if (v == p) continue; // BCC && 2ECC
        // use egde id for multiple edges
        if (!vis[v]) {
            leaf[u] = false; 
            depth[v] = depth[u] + 1;
            child++;
            dfs(v, u);
            height[u] = max(height[u], height[v] + 1);
            subtree_sz[u] += subtree_sz[v];
            low[u] = min(low[u], low[v]);

            // --- BCC---
            edge_stk.push_back({u, v});
            if (low[v] >= tin[u]) {
                if (p != 0) cutpoint[u] = true;
                bcc_cnt++;
                vector<int> bcc;
                while (true) {
                    auto [f, s] = edge_stk.back();
                    edge_stk.pop_back();
                    bcc.push_back(f);
                    bcc.push_back(s);
                    if (f == u && s == v) break;
                }
                sort(all(bcc));
                bcc.erase(unique(all(bcc)), bcc.end());
                bccs.push_back(bcc);
            }
            // ----------------------------------------
        }
        else if (in_stk[v]) { 
            // BCC
            if (tin[v] < tin[u]) {
                edge_stk.push_back({u, v});
            }
            // all
            low[u] = min(low[u], tin[v]);
        }
    }
    if (p == 0 && child > 1) cutpoint[u] = true; //BCC
    tout[u] = timer;
    
    // --- SCC && 2ECC ---
    if (low[u] == tin[u]) {
        comp_cnt++;
        vector<int> comp;
        while (true) {
            int node = stk.back();
            stk.pop_back();
            in_stk[node] = false;
            comp_id[node] = comp_cnt;
            comp.push_back(node);
            if (node == u) break;
        }
        comps.push_back(comp);
    }
}
