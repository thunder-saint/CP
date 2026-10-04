struct Manacher {
    vector<int> p;
    Manacher(const string& s) {
        string t = "^";
        for (char c : s) t += "#", t += c;
        t += "#$";
        int n = t.length();
        p.assign(n, 0);
        int c = 0, r = 0;
        for (int i = 1; i < n - 1; i++) {
            int mir = 2 * c - i;
            if (r > i) p[i] = min(r - i, p[mir]);
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) c = i, r = i + p[i];
        }
    }
    bool is_palindrome(int l, int r) const {
        int center = l + r + 2; radius = r - l + 1; 
        return p[center] >= radius;
    }
};
