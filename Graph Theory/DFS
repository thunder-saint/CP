const int N = 1e5 + 1;
vector<int> g[N];
bool vis[N];
int depth[N], subtree_sz[N], height[N];
void dfs(int source) {
    vis[source] = true;
    subtree_sz[source] = 1;
    for (auto &v : g[source]) {
        if (!vis[v]) {
            depth[v] = depth[source] + 1;
            dfs(v);
            height[source]=max(height[source],height[v]+1);
            subtree_sz[source] += subtree_sz[v];
        }
    }
}
