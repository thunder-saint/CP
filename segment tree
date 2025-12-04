const int N = 3e5+1;
int a[N];
struct ST {
    int t[4 * N];
    static const int neut = LLONG_MIN; // Neutral element (0 for sum, inf for min)

    ST() {
        memset(t,0, sizeof t);
    }
    inline int merge(int a, int b) {
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
        t[n] = merge(t[l], t[r]);
    }

    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = merge(t[l], t[r]);
    }

    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return neut;
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
} tr;
