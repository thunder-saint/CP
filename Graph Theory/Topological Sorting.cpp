const int N = 1e5 + 1;
int indeg[N];
vector<int> g[N];
vector<int> Topological_sort(int n) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        ans.push_back(cur);

        for (auto v : g[cur]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if (ans.size() != n) return {};
    return ans;
}
