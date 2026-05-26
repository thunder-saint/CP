const int INF = 1e18;
vector <tuple<int,int,int>> e;
vector<long long> d, p, nc; 
bool neg = false;
void bellman_ford(int s, int n, bool fl) {
    d.assign(n + 1, fl ? 0 : INF);
    p.assign(n + 1, -1), nc.clear();
    neg = false, d[s] = 0; 
    int l = -1;
    for (int i = 1; i <= n; ++i) {
        l = -1;
        for (auto &[u, v, w]  : e) {
            if (d[u] < INF && d[u] + w < d[v]) {
                d[v] = d[u] + w, p[v] = u, l = v;
            }
        }
        if (l == -1) return;
    }
    neg = true;
    for(int i = 1; i <= n; i++) l = p[l];
    nc.push_back(l); int c = p[l];
    while(c != l) nc.push_back(c), c = p[c];
    nc.push_back(l), reverse(all(nc));
    for (int i = 1; i <= n; ++i) {
        for (auto &[u,v,w] : e) {
            if (d[u] < INF) {
                if (d[u] == -INF || d[u] + w < d[v]) d[v] = -INF;
            }
        }
    }
}
