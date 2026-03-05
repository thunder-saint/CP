int mulmod(int x, int y, int mod) {
  int ans = 0;
  while (y) {
    if (y & 1) ans = (ans + x) % mod;
    x = (x + x) % mod;
    y >>= 1;
  }
  return ans;
}
