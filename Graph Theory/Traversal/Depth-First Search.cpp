const int N = 1e5 + 1;
vector<int> g[N];
const int LOG = 31;
int up[N][LOG], par[N];
bool vis[N], leaf[N];
int depth[N], subtree_sz[N], height[N];
int tin[N], tout[N], flat_tree[N];
int timer = 0;
void dfs(int u, int p ) {
    flat_tree[timer] = u;
    tin[u] = timer++; 
    vis[u] = leaf[u] = true;
    height[u] = 0, subtree_sz[u] = 1;
    par[u] = up[u][0] = p;
    for (auto &v : g[u]) {
        if(v == p) continue;
        if (!vis[v]) {
            leaf[u] = false; 
            depth[v] = depth[u] + 1;
            dfs(v,u);
            height[u]=max(height[u],height[v]+1);
            subtree_sz[u] += subtree_sz[v];
        }
    }
    tout[u] = timer;
}
