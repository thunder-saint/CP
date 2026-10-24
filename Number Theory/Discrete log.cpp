int discrete_log(int a, int b, int m) {
  static const int inf = 2e9;
  int n = (int) sqrt (m + .0) + 1;
  int pw = 1;
  for (int i = 0; i < n; ++i) pw = 1LL * pw * a % m;
  gp_hash_table<int, int> vals;
  for (int p = 1, cur = pw; p <= n; ++p) {
    if (!vals[cur]) vals[cur] = p;
    cur = 1LL * cur * pw % m;
  }
  int ans = inf;
  for (int q = 0, cur = b; q <= n; ++q) {
    if (vals.find(cur) != vals.end()) {
      long long nw = 1LL * vals[cur] * n - q;
      if (nw < ans) ans = nw;
    }
    cur = (1LL * cur * a) % m;
  }
  if (ans == inf) ans = -1;
  return ans;
}

// discrete log but a and m may not be co-prime
int discrete_log_noncoprime(int a, int b, int m) {
  if (m == 1) return 0;
  if (b == 1) return 0;
  if (__gcd(a, m) == 1) return discrete_log(a, b, m);
  int g = __gcd(a, m);
  if (b % g != 0)  return -1;
  int p = inverse(a / g, m / g);
  int nw = discrete_log_noncoprime(a, 1LL * b / g * p % (m / g), m / g);
  if (nw == -1) return -1;
  return nw + 1;
}
