const int N = 1e6 + 1;
const int p1 = 137, p2 = 277;
const int mod1 = 127657753, mod2 = 987654319;
int ip1, ip2;
pair <int,int> pw[N], ipw[N];
void pre() {
    pw[0] = ipw[0] = {1,1};
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    for(int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
        ipw[i].first = 1LL * ipw[i-1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i-1].second * ip2 % mod2;
    }
} 
pair<int, int> string_hash(const string &s)) {
    int n = s.size();
    pair<int, int> hs({0, 0});
    for(int i = 0; i < n; i++) {
        hs.first = (hs.first + (s[i] * pw[i].first)) % mod1;
        hs.second = (hs.second + (s[i] * pw[i].second)) % mod2;
    }
    return hs;
}
// for substring hashing
struct Hashing {
    pair<int, int> pref[N];
    void build(const string &s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            pref[i].first = 1LL * s[i] * pw[i].first % mod1;
            if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
            pref[i].second = 1LL * s[i] * pw[i].second % mod2;
            if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
        }
    }
    pair<int, int> get_hash(int i, int j) {
        assert(i<=j);
        pair<int, int> hs({0, 0});
        hs.first = pref[j].first;
        if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
        hs.first = 1LL * hs.first * ipw[i].first % mod1;
        hs.second = pref[j].second;
        if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
        hs.second = 1LL * hs.second * ipw[i].second % mod2;
        return hs;
    }
};
// for queries
int lcp(int i, int j, int x, int y) {
    int l = 1, r = min(j-i+1, y-x+1), ans=0;
    while(l<=r) {
        int mid = (l+r) >> 1;
        if(get_hash(i, i+mid-1) == get_hash(x, x+mid-1)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int compare(int i, int j, int x, int y) {
  int lc = lcp(i, j, x, y);
  int len1 = j - i + 1, len2 = y - x + 1;
  if (len1 == len2 && len1 == lc) return 0;
  else if (lcp == len1) return -1;
  else if (lcp == len2) return 1;
  else if (s[i + lcp] > s[x + lcp]) return 1;
  else return -1;
}
//palindrome detectrion
vector <int> odd, even;
bool is_palindrome(int i, int j) {
    auto hs1 = S.get_hash(i,j);
    auto hs2 = R.get_hash(n-j-1, n-i-1);
    return (hs1 == hs2);
}
void palindrome(const string &s) {
    string f;
    f = s;
    odd.resize(n), even.resize(n);
    reverse(all(f));
    S.build(s), R.build(f);
    for(int i=0; i<n; i++) {
        int l = 0, r = min(i, n-i-1), ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(is_palindrome(i - mid, i + mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        odd[i] = ans;
    }
    for(int i=0; i<n; i++) {
        int l = 1, r = min(i, n-i), ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(is_palindrome(i-mid, i+mid-1)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        even[i] = ans;
    }
}
