#define pi pair<int, int>
const int N = 1e5 + 1;
const int inf = 1e18+1;
vector<pi> g[N];
int d[N], p[N], c[N], mn[N], mx[N];
void dijkstra(int s, int n) {
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    for (int i = 1; i <= n; i++) {
        d[i] = mn[i] = inf;
        c[i] = p[i] = mx[i] = 0;
    }
    d[s] = mn[s] = mx[s] = 0;
    c[s] = 1;
    pq.push({0, s});
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
