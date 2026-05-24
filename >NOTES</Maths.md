# **Algebra:**
- if (a*b)<=n then a<=(n/b).
---
# **Pigeonhole Principle:**
- if N+1 objects are put into N boxes, then at least one box contains 2 or more objects.
- in any array of N positive integers, there exists a non-empty contiguous subarray whose sum is divisible by N.
---

# **GCD & LCM:**
- gcd(a,b) = gcd(|a|, |b|);
- gcd(a,b) = gcd(a-b, b) = gcd(a%b, b) : where a >= b;
- if g = gcd(a,b) then, gcd(a/g, b/g) = 1;
- if a1 and a2 are coprime, then: gcd(a1*a2, b) = gcd(a1, b) * gcd(a2 * b);
- gcd(a, lcm(b,c)) = lcm(gcd(a,b), gcd(a,c)); 

# **Special Number Series:**
- The (n+2)th fibonacci number counts binary sequences of length n with no consecutive 1s (equivalently, no consecutive 0s).
---

# **Things Related to Ranges:**
- for any pair (x, y) a target sum S is reachable with exactly one change with [1,k] if it falls in the range [min(x, y)+1, max(x, y)+k].
---

# **Things Related to odd-even:**
- Use the "least even" logic only as a last resort to break a perfectly balanced, even-sum array.
---

# **Statistical Optimization:**
- Median minimizes the sum of absolute deviations.
---
# **Others:**
- The k-th positive number n with digital root x is given by: n = x + 9*(k - 1).
