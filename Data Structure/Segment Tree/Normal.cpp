const int N = 3e5 + 1;
int a[N];
struct Segment_Tree {
    static const int neut = 0; // <--- CHANGE
    vector<int> t; // <--- CHANGE
    Segment_Tree(int n) {
        t.assign(4 * n, 0);
    }
    inline int merge(int a, int b) { // <--- CHANGE
        return a + b; 
    }
    inline void pull(int n) {
        int l = n << 1, r = l | 1;
        t[n] = merge(t[l], t[r]); // <--- CHANGE
    }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[b]; // <--- CHANGE
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        pull(n);
    }
    void update(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x; // <--- CHANGE (e.g., t[n] += x)
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        update(l, b, mid, i, x);
        update(r, mid + 1, e, i, x);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return neut; // <--- CHANGE
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int q1 = query(l, b, mid, i, j);
        int q2 = query(r, mid + 1, e, i, j);
        return merge(q1, q2);
    }
    int find(int n, int b, int e, int ql, int qr, int &k) { // pass k
        if (b > qr || e < ql || k <= 0) return -1;
        if (ql <= b && e <= qr) {
            if (t[n] < k) {
                k -= t[n];// skip to find k, keep to find kth
                return -1;
            }
            if (b == e) return b;
            int mid = (b + e) >> 1, l = n << 1, r = l | 1;
            if (t[l] >= k) return find(l, b, mid, ql, qr, k);
            k -= t[l]; // skip to find k, keep to find kth
            return find(r, mid + 1, e, ql, qr, k);
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int left_res = find(l, b, mid, ql, qr, k);
        if (left_res != -1) return left_res;
        return find(r, mid + 1, e, ql, qr, k);
    }
};
