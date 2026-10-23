struct Manacher {
    string s;
    int n;
    vector<int> p[2];
    void build(const string &str) {
        s = str;
        n = s.size();
        p[0].assign(n + 1, 0); p[1].assign(n, 0);
        for (int z = 0; z < 2; z++) {
            for (int i = 0, l = 0, r = 0; i < n; i++) {
                int t = r - i + !z;
                if (i < r) p[z][i] = min(t, p[z][l + t]);
                int L = i - p[z][i], R = i + p[z][i] - !z;
                while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) {
                    p[z][i]++, L--, R++;
                }
                if (R > r) l = L, r = R;
            }
        }
    }
    bool is_palindrome(int l, int r) const {
        int len = r - l + 1, mid = l + len / 2;
        if (len % 2 != 0) return p[1][mid] >= len / 2;
        else return p[0][mid] >= len / 2;
    }
    int get_max_radius(int i, bool odd) const {
        return p[odd ? 1 : 0][i];
    }
    int count_all_palindromes() const {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += p[1][i] + 1, total += p[0][i];   
        }
        return total;
    }
    string get_longest_palindrome() const {
        int max_len = 0, start_idx = 0;
        for (int i = 0; i < n; i++) {
            int odd_len = 2 * p[1][i] + 1;
            if (odd_len > max_len) {
                max_len = odd_len;
                start_idx = i - p[1][i];
            }
            int even_len = 2 * p[0][i];
            if (even_len > max_len) {
                max_len = even_len;
                start_idx = i - p[0][i];
            }
        }
        return s.substr(start_idx, max_len);
    }
};
