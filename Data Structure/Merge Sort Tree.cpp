const int N = 5e5 + 9;
const int INF = LLONG_MAX;
int a[N];
struct MergeSortTree {
#define lc (n << 1LL)
#define rc ((n << 1LL) | 1LL)
    vector<ordered_multiset<int>> t;
    MergeSortTree(int n) {
        t.resize(4 * n + 1);
    }
    void build(int n, int b, int e) {
        for (int i = b; i <= e; i++) t[n].insert(a[i]);
        if (b == e) return;
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
    }
    void update(int n, int b, int e, int i, int old, int nw) {
        auto it = t[n].upper_bound(old);
        if (it != t[n].end() && *it == old) {
            t[n].erase(it);
        }
        t[n].insert(nw);
        if (b == e) return;
        int mid = (b + e) >> 1;
        if (i <= mid) update(lc, b, mid, i, old, nw);
        else update(rc, mid + 1, e, i, old, nw);
    }
    template <typename Condition>
    int query_base(int n, int b, int e, int i, int j, const Condition& cond) {
        if (i > e || b > j) return 0;
        if (i <= b && e <= j) return cond(t[n]);
        int mid = (b + e) >> 1;
        int q1 = query_base(lc, b, mid, i, j, cond);
        int q2 = query_base(rc, mid + 1, e, i, j, cond);
        return q1 + q2;
    }

    int count(int n, int b, int e, int i, int j, int k) {
        return query_base(n, b, e, i, j, [&](const ordered_multiset<int>& node) {
            // return node.order_of_key(k); // lt
            // return node.order_of_key(k + 1); // lte
            // return node.size() - node.order_of_key(k + 1); // gt
            // return node.size() - node.order_of_key(k); // gte
            // return node.order_of_key(k + 1) - node.order_of_key(k); // eq
            // return node.order_of_key(k2 + 1) - node.order_of_key(k1); // range;
        });
    }
    int get_closer(int val1, int val2, int X) {
        if (val1 == INF) return val2;
        if (val2 == INF) return val1;
        return abs(val1 - X) < abs(val2 - X) ? val1 : val2;
    }
    int closest_value(int n, int b, int e, int i, int j, int X) {
        if (i > e || b > j) return INF; 
        if (i <= b && e <= j) {
            int best_val = INF;
            auto it = t[n].upper_bound(X); 
            if (it != t[n].end()) best_val = *it; 
            if (it != t[n].begin()) {
                auto prev_it = prev(it);
                best_val = get_closer(best_val, *prev_it, X);
            }
            return best_val;
        }
        int mid = (b + e) >> 1;
        int q1 = closest_value(lc, b, mid, i, j, X);
        int q2 = closest_value(rc, mid + 1, e, i, j, X); 
        return get_closer(q1, q2, X);
    }
};b
