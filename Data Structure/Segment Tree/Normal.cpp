const int N = 3e5 + 1;
int a[N];
struct Segment_Tree {
    static const int neut = LLONG_MIN; // <--- CHANGE
    vector<int> t; // <--- CHANGE
    Segment_Tree(int n) {
        t.assign(4 * n, 0);
    }
    inline int merge(int a, int b) { // <--- CHANGE
        return max(a, b); 
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
        if (b > j || e < i) return neut; 
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
};
