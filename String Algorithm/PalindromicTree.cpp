const int MAXN = 100005;
const int ALPHABET = 26; // 52 u // 62 num 
struct Node {
    int next[ALPHABET], len, link; 
    int cnt, depth; 
};
struct PalindromicTree {
    Node tree[MAXN];
    int sz, last;
    vector<int> s;
    void build() {
        sz = last = 0;
        s.clear();
        tree[0].len = tree[0].cnt = tree[0].depth = 0;
        tree[0].link = 1;
        memset(tree[0].next, 0, sizeof(tree[0].next));
        tree[1].len = -1;
        tree[1].link = 1;
        tree[1].cnt = tree[1].depth = 0;
        memset(tree[1].next, 0, sizeof(tree[1].next));
        sz = 2;
    }
    int get_link(int curr) {
        int pos = s.size() - 1;
        while (pos - 1 - tree[curr].len < 0 || s[pos - 1 - tree[curr].len] != s[pos]) {
            curr = tree[curr].link;
        }
        return curr;
    }
    bool add(char ch) {
        int c = ch - 'a';
        s.push_back(c);
        int curr = get_link(last);
        bool is_new = false;
        if (!tree[curr].next[c]) {
            int node = sz++;
            tree[node].len = tree[curr].len + 2;
            memset(tree[node].next, 0, sizeof(tree[node].next));
            int link_curr = get_link(tree[curr].link);
            tree[node].link = (tree[node].len == 1) ? 0 : tree[link_curr].next[c];
            tree[node].depth = tree[tree[node].link].depth + 1;
            tree[curr].next[c] = node;
            is_new = true;
        }
        last = tree[curr].next[c];
        tree[last].cnt++;
        return is_new;
    }
    void compute_frequencies() {
        for (int i = sz - 1; i > 1; i--) {
            tree[tree[i].link].cnt += tree[i].cnt;
        }
    }
    int count_unique() {
        return sz - 2;
    }
};
