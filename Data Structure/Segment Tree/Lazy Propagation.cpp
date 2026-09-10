const int N = 5e5 + 9;
int a[N];
struct Segment_Tree {
#define lc (n << 1LL)
#define rc ((n << 1LL) | 1LL)
    static const int neut_query = 0; // CHANGE 
    static const int neut_lazy = -1;  //  CHANGE 
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
        push(n, b, e);
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
           apply(n, b, e, v);
           return;
        }
        int mid = (b + e) >> 1;
        update(lc, b, mid, i, j, v);
        update(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j) return neut_query; // CHANGE
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        int q1 = query(lc, b, mid, i, j);
        int q2 = query(rc, mid + 1, e, i, j);
        return merge(q1, q2);
    }
    int find(int n, int b, int e, int k) {
        push(n, b, e);
        if (t[n] < k || k <= 0) return -1; // CHANGE
        if (b == e) return b;
        int mid = (b + e) >> 1;
        if (t[lc] >= k) return find(lc, b, mid, k);
        else return find(rc, mid + 1, e, k - t[lc]);
    }
};
