const int N = 1e5 + 1;
const int LOG = 31;
vector<int> g[N], stk;
vector<vector<int>> sccs;
int up[N][LOG], par[N];
bool vis[N], leaf[N], in_stk[N];
int depth[N], subtree_sz[N], height[N];
int tin[N], tout[N], flat_tree[N];
int low[N], comp_id[N];
int timer = 0, scc_cnt = 0;
void dfs(int u, int p ) {
    tin[u] = low[u] = ++timer;
    flat_tree[timer] = u;
    height[u] = 0, subtree_sz[u] = 1;
    par[u] = up[u][0] = p;
    vis[u] = leaf[u] = in_stk[u] = true;
    stk.push_back(u);
    for (auto &v : g[u]) {
        if (!vis[v]) {
            leaf[u] = false; 
            depth[v] = depth[u] + 1;
            dfs(v,u);
            height[u]=max(height[u],height[v]+1);
            subtree_sz[u] += subtree_sz[v];
            low[u] = min(low[u], low[v]);
        }
        else if (in_stk[v]) { 
            low[u] = min(low[u], tin[v]);
        }
    }
    tout[u] = timer;
    if (low[u] == tin[u]) {
        scc_cnt++;
        vector<int> scc;
        while (true) {
            int node = stk.back();
            stk.pop_back();
            in_stk[node] = false;
            comp_id[node] = scc_cnt;
            scc.push_back(node);
            if (node == u) break;
        }
        sccs.push_back(scc);
    }
}
