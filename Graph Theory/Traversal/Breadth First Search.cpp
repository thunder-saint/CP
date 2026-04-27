const int N = 1e5 + 1;
vector<int> g[N];
int dist[N], par[N];
bool vis[N];
void bfs(int s) {
    queue<int> q;
    dist[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}
