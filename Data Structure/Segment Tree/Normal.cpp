const int N = 3e5+1;
int a[N];
struct Segment_Tree {
    int t[4 * N];
    static const int neut = LLONG_MIN; // Neutral element (0 for sum, inf for min)
    Segment_Tree() {
        memset(t,0, sizeof t);
    }
    inline int operation(int a, int b) {
        return max(a, b); // Operation
    }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = operation(t[l], t[r]);
    }
    void update(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        update(l, b, mid, i, x);
        update(r, mid + 1, e, i, x);
        t[n] = operation([l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return neut;
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        return operation(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
};
