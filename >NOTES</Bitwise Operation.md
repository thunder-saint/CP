# **Bit Operations:**
- Toggle the kth bit: (x ⊕ (1 << k));
- Set the kth bit: (x | (1 << k));
- Unset the kth bit: (x &~ (1 << k));
- Check if the kth bit is On/Off: (x & (1<<k));
- Off all bits except last k: (x & (1 << k ) - 1);
---
# **Bit Tricks:**
- A number with only the lowest set bit of x turned on: ( x & (-x))
- Is Power of 2?:	x & (x - 1) == 0;
- Remove LSB:	x & (x - 1);
- Submusk: (x & y) == y;
- Clear LSB upto kth bit : ( x & ~((1 << (k + 1)) - 1));
- Clear MSB upto kth bit : ( x & ((1 << (k + 1)) - 1));
---

# **Power of 2:**
- x / (2^k) = (x >> k);
- x * (2^k) = (x << k);
- x % (2^k) = x & ((1 << k) - 1); 
---

# **Swapping**: 
- x = x ⊕ y;
- y = x ⊕ y;
- x = x ⊕ y;
# **Swap adjacent bits:** 
- ((n & 0xAAAAAAAA) >> 1 ) | ((n & 0x55555555) << 1)
---

# **Bit reversal:**
- if (n & (1<<i))  s|= ( 1 << (len - 1 - i));
---

# Formulas:

$$
\begin{aligned}
(A \mid B) &= (A \oplus B) + (A \mathbin{\&} B) \\
(A \oplus B) &= (A \mathbin{\&} B) \oplus (A \mid B) \\
\\
(A \oplus (A \mathbin{\&} B)) &= ((A \mid B) \oplus B) \\
&= (A \mathbin{\&} \sim B) \\
\\
(A \oplus (A \mid B)) &= ((A \mathbin{\&} B) \oplus B) \\
&= (B \mathbin{\&} \sim A) \\
\\
(A + B) &= (A \oplus B) + 2(A \mathbin{\&} B) \\
&= (A \mid B) + (A \mathbin{\&} B) \\
\\
(A - B) &= (A \oplus (A \mathbin{\&} B)) - (A \oplus (A \mid B)) \\
&= ((A \mid B) \oplus B) - (A \oplus (A \mid B)) \\
&= (A \oplus (A \mathbin{\&} B)) - ((A \mathbin{\&} B) \oplus B) \\
&= ((A \mid B) \oplus B) - ((A \mathbin{\&} B) \oplus B)
\end{aligned}
$$
---

# **Tips:**
- (A | B) <= (A + B);
- if A,B>0 then: (A & B) <= min(A,B)
- if x is even, then: (x+1) = (x⊕1);
- if (A & B = 0): (A + B) = (A ⊕ B) = (A | B);
---

   





