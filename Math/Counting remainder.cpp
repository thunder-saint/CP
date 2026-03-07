// Returns the count of non-negative integers p in the range [0, x] such that (p % n == rem).
int count_rem(int x, int rem, int n) {
    if (x < rem) return 0;
    return (x - rem) / n + 1;
}
