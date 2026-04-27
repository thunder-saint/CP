#define pi pair<int,int>
const int N = 1e5 + 1;
const int inf = 1e18;
vector <pi> g[N];
int dist[N], par[N], cnt[N], mn[N], mx[N];
void dijkstra(int source, int n) {
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    for(int i=1; i<=n; i++) {
        dist[i] = mn[i] = inf;
        cnt[i] = par[i] = mx[i] = 0;
    }
    dist[source] = mn[source] = mx[source] = 0;
    cnt[source] = 1;
    pq.push({0, source});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto &[v,w] : g[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v}); 
            }
        }
    } 
    // extra
    vector<int> in(n + 1, 0);
     for (int u = 1; u <= n; u++) {
        if (dist[u] == inf) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[u] + w == dist[v]) in[v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (dist[i] < inf && !in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &[v,w] : g[u]) {
            if (dist[u] + w == dist[v]) { 
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                mn[v]  = min(mn[v], mn[u] + 1);
                mx[v]  = max(mx[v], mx[u] + 1);
                if (--in[v] == 0) q.push(v);
            }
        }
    }
}
