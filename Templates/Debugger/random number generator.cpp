mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); 
long long get_rand(long long l, long long r) { 
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}
