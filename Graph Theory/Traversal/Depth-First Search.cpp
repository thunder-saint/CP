const int N = 1e5 + 1;
vector<int> g[N];
int up[N][30];
bool vis[N], leaf[N];
int depth[N], subtree_sz[N], height[N];
int tin[N], tout[N], par[N];
int timer = 0;
void dfs(int u, int p ) {
    tin[u] = ++timer; 
    vis[u] = leaf[u] = true;
    height[u] = 0;  
    subtree_sz[u] = 1;
    par[u] = up[u][0] = p;
    for (int i = 1; i < 30; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
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
