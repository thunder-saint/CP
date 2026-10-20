struct Manacher {
    string s;
    int n;
    vector<int> p[2];
    void build(const string &str) {
        s = str. n = s.size();
        p[0].assign(n, 0), p[1].assign(n, 0);
        for (int z = 0; z < 2; z++) {
            for (int i = 0, l = 0, r = -1; i < n; i++) {
                int y = l + r - i + !z;
                int k = (i > r) ? z : min(p[z][y], r - i + 1);
                int x = i - k - !z;
                while (x >= 0 && i + k < n && s[x] == s[i + k]) k++;
                p[z][i] = --k;
                if (i + k > r) l = i - k - !z, r = i + k;
            }
        }
    }
    bool is_palindrome(int l, int r) const {
        int len = r - l + 1, mid = l + len / 2;
        if (len % 2 == 1) return p[1][mid] >= len / 2;
        else return p[0][mid] >= len / 2;
    }
    int get_max_radius(int i, bool odd) const {
        return p[odd ? 1 : 0][i];
    }
    int count_all_palindromes() const {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += p[1][i] + 1;
            total += p[0][i];   
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
