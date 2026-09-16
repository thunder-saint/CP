const int N = 5e5 + 9;
int a[N];
struct Segment_Tree {
#define lc (n << 1LL)
#define rc ((n << 1LL) | 1LL)
    static const int neut_query = 0; // CHANGE 
    static const int neut_lazy = 0;  //  CHANGE 
    vector<int> t, lazy; // CHANGE
    Segment_Tree(int n) {
        t.assign(4 * n, 0);
        lazy.assign(4 * n, neut_lazy);
    }
    inline void apply(int n, int b, int e, int v) {
        t[n] += v * (e - b + 1); // CHANGE
        lazy[n] += v;            // CHANGE 
    }
    inline void push(int n, int b, int e) { 
        if (lazy[n] == neut_lazy) return;   
        if (b != e) {
            int mid = (b + e) >> 1;
            apply(lc, b, mid, lazy[n]); 
            // may
            apply(rc, mid + 1, e, lazy[n]);
        }
        lazy[n] = neut_lazy;
    }
    inline int merge(int a, int b) {
        return a + b; // CHANGE
    }
    inline void pull(int n) {
        t[n] = merge(t[lc], t[rc]); 
    }
    void build(int n, int b, int e) {
        lazy[n] = neut_lazy; 
        if (b == e) {
            t[n] = a[b]; // CHANGE 
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void update(int n, int b, int e, int i, int j, int v) {
        if (j < b || e < i) return;
        push(n, b, e);
        if (i <= b && e <= j) {
            // may
           apply(n, b, e, v);
           return;
        }
        int mid = (b + e) >> 1;
        update(lc, b, mid, i, j, v);
        update(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        if (i > e || b > j) return neut_query; // CHANGE
        push(n, b, e);
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        int q1 = query(lc, b, mid, i, j);
        int q2 = query(rc, mid + 1, e, i, j);
        return merge(q1, q2);
    }
    int find(int n, int b, int e, int ql, int qr, int &k) { // pass k
        if (b > qr || e < ql || k <= 0) return -1;
        push(n, b, e);
        if (ql <= b && e <= qr) {
            if (t[n] < k) {
                k -= t[n];// skip to find k, keep to find kth
                return -1;
            }
            if (b == e) return b;
            int mid = (b + e) >> 1;
            if (t[lc] >= k) return find(lc, b, mid, ql, qr, k);
            k -= t[lc]; // skip to find k, keep to find kth
            return find(rc, mid + 1, e, ql, qr, k);
        }
        int mid = (b + e) >> 1;
        int left_res = find(lc, b, mid, ql, qr, k);
        if (left_res != -1) return left_res;
        return find(rc, mid + 1, e, ql, qr, k);
    }
};
