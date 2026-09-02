const int N = 5e5 + 9;
int a[N];
struct Segment_Tree {
#define lc (n << 1LL)
#define rc ((n << 1LL) | 1LL)
    static const int neut = 0; // <--- CHANGE
    vector<int> t, lazy;       // <--- CHANGE
    vector<bool> is_lazy;
    Segment_Tree(int n) {
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        is_lazy.assign(4 * n, false);
    }
    inline void push(int n, int b, int e) { // <--- CHANGE
        if (!is_lazy[n]) return;
        t[n] += lazy[n] * (e - b + 1);
        if (b != e) {
            lazy[lc] += lazy[n], is_lazy[lc] = true;
            lazy[rc] += lazy[n], is_lazy[rc] = true;
        }
        lazy[n] = 0;
        is_lazy[n] = false;
    }
    inline int merge(int a, int b) {
        return a + b; // <--- CHANGE
    }
    inline void pull(int n) {
        t[n] = merge(t[lc], t[rc]); // <--- CHANGE
    }
    void build(int n, int b, int e) {
        lazy[n] = neut; // <--- CHANGE
        is_lazy[n] = false;
        if (b == e) {
            t[n] = a[b]; // <--- CHANGE
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
            lazy[n] += v; // <--- CHANGE
            is_lazy[n] = true;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        update(lc, b, mid, i, j, v);
        update(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j) return neut; // <--- CHANGE
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return merge(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
};
