const long long INF = 1e18;
vector<tuple<int, int, int>> e;
vector<long long> d; 
// excludes src and dst;
void shortest_path_k_stops(int s, int n, int k) {
    d.assign(n, INF);
    d[s] = 0;
    for (int i = 0; i <= k; ++i) {
        vector<long long> temp_d = d; 
        for (auto &[u, v, w] : e) {
            if (d[u] < INF && d[u] + w < temp_d[v]) {
                temp_d[v] = d[u] + w;
            }
        }
        swap(d, temp_d);
    }
}
