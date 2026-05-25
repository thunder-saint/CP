const int N = 1e3 + 123;
const int inf = 1e18;
vector<tuple<int, int, int>> e;
int d[N], p[N]; 
bool NegativeCycle;
void bellman_ford(int s, int n) {
    NegativeCycle = false;
    for (int i = 1; i <= n; i++) d[i] = inf, p[i] = -1;
    d[s] = 0;
    for (int i = 1; i < n; i++) {
        bool updated = false;
        for (auto &[u, v, w] : e) {
            if (d[u] < inf && d[u] + w < d[v]) {
                d[v] = max(-inf, d[u] + w);
                p[v] = u, updated = true;           
            }
        }
        if (!updated) return; 
    }
    for (int i = 1; i <= n; i++) {
        for (auto &[u, v, w] : e) {
            if (d[u] < inf && (d[u] == -inf || d[u] + w < d[v]) && d[v] != -inf) {
                d[v] = -inf, NegativeCycle = true;
            }
        }
    }
}
