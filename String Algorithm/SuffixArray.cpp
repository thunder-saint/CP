#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
struct SuffixArray {
    int n;
    string s;
    vector<int> sa, rank, lcp, lg;
    vector<vector<int>> st;
    void induced_sort(const vector<int> &vec, int val, 
        vector<int> &SA, const vector<bool> &sl, 
        const vector<int> &lms_idx) {
        vector<int> l(val, 0), r(val, 0);
        for (int c : vec) {
            if (c + 1 < val) ++l[c + 1];
            ++r[c];
        }
        partial_sum(l.begin(), l.end(), l.begin());
        partial_sum(r.begin(), r.end(), r.begin());
        fill(SA.begin(), SA.end(), -1);
        for (int i = (int)lms_idx.size() - 1; i >= 0; --i) {
            SA[--r[vec[lms_idx[i]]]] = lms_idx[i];
        }
        for (int i : SA) if (i >= 1 && sl[i - 1]) {
            SA[l[vec[i - 1]]++] = i - 1;
        }
        fill(r.begin(), r.end(), 0);
        for (int c : vec) ++r[c];
        partial_sum(r.begin(), r.end(), r.begin());
        for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
            if (i >= 1 && !sl[i - 1]) SA[--r[vec[i - 1]]] = i - 1;
    }
    vector<int> SA_IS(const vector<int> &vec, int val) {
        const int sz = vec.size();
        vector<int> SA(sz), lms_idx;
        vector<bool> sl(sz);
        sl[sz - 1] = false;
        for (int i = sz - 2; i >= 0; --i) {
            sl[i] = (vec[i] > vec[i + 1] || (vec[i] == vec[i + 1] && sl[i + 1]));
            if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);
        }
        reverse(all(lms_idx));
        induced_sort(vec, val, SA, sl, lms_idx);
        vector<int> new_idx(lms_idx.size()), lms_vec(lms_idx.size());
        for (int i = 0, k = 0; i < sz; ++i) {
            if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) new_idx[k++] = SA[i];
        }
        int cur = 0;
        SA[sz - 1] = cur;
        for (size_t k = 1; k < new_idx.size(); ++k) {
            int i = new_idx[k - 1], j = new_idx[k];
            if (vec[i] != vec[j]) { SA[j] = ++cur; continue; }
            bool flag = false;
            for (int a = i + 1, b = j + 1;; ++a, ++b) {
                if (vec[a] != vec[b]) { flag = true; break; }
                if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {
                    flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));
                    break;
                }
            }
            SA[j] = (flag ? ++cur : cur);
        }
        for (size_t i = 0; i < lms_idx.size(); ++i) {
            lms_vec[i] = SA[lms_idx[i]];
        }
        if (cur + 1 < (int)lms_idx.size()) {
            auto lms_SA = SA_IS(lms_vec, cur + 1);
            for (size_t i = 0; i < lms_idx.size(); ++i) {
                new_idx[i] = lms_idx[lms_SA[i]];
            }
        }
        induced_sort(vec, val, SA, sl, new_idx);
        return SA;
    }
    SuffixArray() {}
    SuffixArray(const string &_s, int LIM = 256) : s(_s), n(_s.size()) {
        if (n == 0) return;
        vector<int> vec(n + 1);
        for (int i = 0; i < n; i++) vec[i] = (unsigned char)s[i];
        vec.back() = 0;
        sa = SA_IS(vec, max(LIM, 256) + 1);
        sa.erase(sa.begin());
        rank.resize(n);
        for (int i = 0; i < n; i++) rank[sa[i]] = i;
        build_lcp();
        build_sparse_table();
    }
    void build_lcp() {
        lcp.assign(n - 1, 0);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) { k = 0; continue; }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
            if (k > 0) k--;
        }
    }
    void build_sparse_table() {
        if (n <= 1) return;
        int sz = n - 1;
        lg.assign(sz + 1, 0);
        for (int i = 2; i <= sz; i++) lg[i] = lg[i / 2] + 1;
        int max_log = lg[sz] + 1;
        st.assign(max_log, vector<int>(sz));
        for (int i = 0; i < sz; i++) st[0][i] = lcp[i];
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= sz; i++) {
                int x = i + (1 << (j - 1));
                st[j][i] = min(st[j - 1][i], st[j - 1][x]);
            }
        }
    }
    int query_sa_range(int l, int r) {
        if (l > r) swap(l, r);
        if (l == r) return n - sa[l];
        int k = lg[r - l];
        return min(st[k][l], st[k][r - (1 << k)]);
    }
    int get_lcp(int i, int j) {
        if (i == j) return n - i;
        int r1 = rank[i], r2 = rank[j];
        return query_sa_range(r1, r2);
    }
    int count_distinct_substrings() {
        long long total = 1LL * n * (n + 1) / 2;
        for (int x : lcp) total -= x;
        return total;
    }
    pair<int, int> find_pattern(const string &p) {
        int m = p.size();
        int low = 0, high = n - 1, L = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (s.compare(sa[mid], m, p) >= 0) { 
                L = mid; high = mid - 1; 
            }
            else low = mid + 1;
        }
        low = 0; high = n - 1;
        int R = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (s.compare(sa[mid], m, p, 0, m) == 0) {
                R = mid; low = mid + 1; 
            }
            else if (s.compare(sa[mid], m, p) < 0) low = mid + 1;
            else high = mid - 1;
        }
        if (L <= R && s.compare(sa[L], m, p, 0, m) == 0) return {L, R};
        return {-1, -1};
    }
    pair<int, int> find_occurrence_range(int p, int len) {
        p = rank[p];
        pair<int, int> ans = {p, p};
        int l = 0, r = p - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (query_sa_range(mid, p) >= len) {
                 ans.first = mid; r = mid - 1; 
                }
            else l = mid + 1;
        }
        l = p + 1; r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (query_sa_range(p, mid) >= len) {
                 ans.second = mid; l = mid + 1; 
                }
            else r = mid - 1;
        }
        return ans;
    }
    string kth_distinct_substring(long long k) {
        for (int i = 0; i < n; i++) {
            int len = n - sa[i];
            int prev_lcp = (i == 0) ? 0 : lcp[i - 1];
            int new_substrings = len - prev_lcp;
            if (k <= new_substrings) {
                return s.substr(sa[i], prev_lcp + k);
            }
            k -= new_substrings;
        }
        return "";
    }
};
string lcs(const string &s1, const string &s2) {
    string combined = s1 + '#' + s2;
    int n1 = s1.size();
    SuffixArray sa(combined);
    int mx = 0, idx = -1;
    for (int i = 0; i < (int)sa.lcp.size(); i++) {
        bool in_s1_first = sa.sa[i] < n1;
        bool in_s1_second = sa.sa[i + 1] < n1;
        if (in_s1_first != in_s1_second) {
            if (sa.lcp[i] > mx) {
                mx = sa.lcp[i], idx = sa.sa[i];
            }
        }
    }
    if (mx == 0) return "";
    return combined.substr(idx, mx);
}
