vector<int> lps(const string& p) {
    int m = p.length();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}
// vector<int> freq; 
vector<int> kmp(const string& t, const string& p) {
    vector<int> matches;
    if (p.empty()) return matches;
    vector<int> pi = lps(p);
    int n = t.length(), m = p.length();
    freq.resize(m + 1);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];
        if (t[i] == p[j]) j++;
        // freq[j]++; 
        if (j == m) {
            matches.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    // for (int i = m; i > 0; i--) {
    //     if (pi[i - 1] > 0) {
    //         freq[pi[i - 1]] += freq[i];
    //     }
    // }
    return matches;
}
int get_shortest_period(const string& p) {
    int n = p.length();
    vector<int> pi = lps(p);
    int len = n - pi[n - 1];
    return (n % len == 0) ? len : n; 
}
vector<vector<int>> automaton(const string& p) {
    int m = p.length();
    vector<int> pi = lps(p);
    vector<vector<int>> aut(m + 1, vector<int>(26));
    for (int i = 0; i <= m; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && (i == m || c != p[i] - 'a')) {
                aut[i][c] = aut[pi[i - 1]][c]; 
            } 
            else aut[i][c] = i + (c == p[i] - 'a'); 
        }
    }
    return aut;
}
