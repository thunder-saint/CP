const int N = 1e3 + 123;
const int inf = 1e18;
vector<tuple<int, int, int>> e;
int d[N], p[N]; 
bool Neg;
vector<int> nc;
void bellman_ford(int s, int n) {
    for (int i = 1; i <= n; i++) d[i] = inf, p[i] = -1;
    d[s] = 0, p[s] = s, Neg = false, nc.clear();;
    for (int i = 1; i <= n; i++) {
        bool updated = false;
        for (auto &[u, v, w] : e) {
            if (d[u] < inf && d[u] + w < d[v]) {
                d[v] = d[u] + w, p[v] = u, updated = true;           
            }
        }
        if (!updated) break; 
    }
    int x = -1;
    for (int i = 1; i <= n; i++) {
        for (auto &[u, v, w] : e) {
            if (d[u] < inf && (d[u] == -inf || d[u] + w < d[v])){
                d[v] = -inf, x = v, Neg = true;
            }
        }
    }
    if(x == -1) return;
    for(int i = 1; i <= n; i++) x = p[x];
    nc.push_back(x);
    int c = p[x];
    while(c != x) nc.push_back(c), c = p[c];
    nc.push_back(x), reverse(all(nc));
}
