# **Bit**:
- to count set bit: __builtin_popcountll(x);
- to count Leading Zeros: __builtin_clz(x);
- to count Trailing Zeros: __builtin_ctz(x);
---

# **String:**
- to store string s as number : stoll(s);
- to store a number as string : to_string(n);
- to convert a char to string (x times): string(x, char);
- to check if a string is in another string:
    - if(s.find(str) != string::npos);
- to get substring of length len from a string s, starting from index i: 
    - s.substr(i,len);
---

# **Bitset:**
- to set every bit as 1: bt.set();
- to set every bit as 0: bt.reset();
- count of 1: bt.count();
- to flip: bt.flip();
- to check at last one bit is 1: bt.any();
- to check all are 0: bt,none(); 
- binary string to number: bt.to_ullong();
---

# **Others:**
- rotate(1st, new 1st, end);
