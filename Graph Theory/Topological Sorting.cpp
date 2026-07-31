const int N = 1e5 + 1;
vector<int> g[N];
int indeg[N], sz[N]; 
vector<int> Topological_sort(int n) {
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        sz[i] = 1; 
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (auto v : g[cur]) {
            sz[v] += sz[cur];
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)ans.size() != n) return {};
    return ans;
}
