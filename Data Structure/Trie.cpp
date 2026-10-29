struct Trie {
  static const int B = 31;
  struct node {
    node* nxt[2];
    int sz;
    node() {
      nxt[0] = nxt[1] = NULL, sz = 0;
    }
  }*root;
  Trie() {
    root = new node();
  }
  ~Trie() {
    del(root);
  }
  void insert(int val) {
    node* cur = root;
    cur->sz++;
    for (int i = B - 1; i >= 0; i--) {
      int b = val >> i & 1;
      if (cur->nxt[b] == NULL) {
        cur->nxt[b] = new node();
      }
      cur = cur->nxt[b], cur->sz++;
    }
  }
  void erase(int val) {
    if (root->sz == 0) return;
    node* cur = root;
    cur->sz--;
    for (int i = B - 1; i >= 0; i--) {
      int b = val >> i & 1;
      cur = cur->nxt[b], cur->sz--;
    }
  }
  int query(int x, int k) { 
    if (root->sz == 0) return 0; //
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--) {
      if (cur == NULL || cur->sz == 0) break;
      int b1 = x >> i & 1, b2 = k >> i & 1;
      if (b2 == 1) {
        if (cur->nxt[b1] && cur->nxt[b1]->sz > 0) {
            ans += cur->nxt[b1]->sz;
        }
        cur = cur->nxt[!b1];
      } 
      else cur = cur->nxt[b1];
    }
    return ans;
  }
  int get_max(int x) { 
    if (root->sz == 0) return 0; //
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--) {
      int k = x >> i & 1;
      if (cur->nxt[!k] && cur->nxt[!k]->sz > 0) {
        cur = cur->nxt[!k], ans = (ans << 1) + 1;
      }
      else cur = cur->nxt[k], ans <<= 1;
    }
    return ans;
    // min: k in if, !k in else, swap ans cnd.
  }
  void del(node* cur) {
    if (!cur) return;
    for (int i = 0; i < 2; i++) {
        if (cur->nxt[i]) del(cur->nxt[i]);
    }
    delete cur;
  }
};
