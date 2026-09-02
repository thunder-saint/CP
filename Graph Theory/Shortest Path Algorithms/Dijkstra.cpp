#define pi pair<int, int>
const int N = 5e5 + 1;
const int inf = 1e18+1;
vector<pi> g[N];
vector<int> dist[N];
int d[N], p[N], c[N], mn[N], mx[N];
void dijkstra(int s, int n) {
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    for (int i = 1; i <= n; i++) {
        d[i] = mn[i] = inf;
        c[i] = mx[i] = 0, p[i] = -1;
        // dist[i].clear();
    }
    d[s] = mn[s] = mx[s] = 0;
    c[s] = 1;
    pq.push({0, s});
    //--K-TH SHORTEST PATH ---
    // while (!pq.empty()) {
    //     auto [W, u] = pq.top(); pq.pop();
    //     if (dist[u].size() >= k) continue;
    //     dist[u].push_back(W);
    //     for (auto &[v, w] : g[u]) {
    //         if (dist[v].size() < k) pq.push({W + w, v});
    //     }
    // }
    // return;
    //------------------------------------------
    while (!pq.empty()) {
        auto [W, u] = pq.top();
        pq.pop();
        if (W > d[u]) continue;
        for (auto &[v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                c[v] = c[u], p[v] = u;
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({d[v], v});
            }
            else if (d[u] + w == d[v]) {
                c[v] = (c[v] + c[u]) % MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }
}
