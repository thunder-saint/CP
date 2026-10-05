struct Trie {
  struct node {
    node* nxt[26];
    int prefix_cnt, word_cnt;
    node() {
      for (int i = 0; i < 26; i++) nxt[i] = NULL;
      prefix_cnt = word_cnt = 0;
    }
  }*root;
  Trie() {
    root = new node();
  }
  ~Trie() {
    del(root);
  }
  void insert(const string& s) {
    node* cur = root;
    for (char c : s) {
      int idx = c - 'a';
      if (cur->nxt[idx] == NULL) {
        cur->nxt[idx] = new node();
      }
      cur = cur->nxt[idx];
      cur->prefix_cnt++;
    }
    cur->word_cnt++;
  }
  void erase(const string& s) {
    node* cur = root;
    for (char c : s) {
      int idx = c - 'a';
      cur = cur->nxt[idx];
      cur->prefix_cnt--;
    }
    cur->word_cnt--;
  }
  int count(const string& s) {
    node* cur = root;
    for (char c : s) {
      int idx = c - 'a';
      if (cur->nxt[idx] == NULL) return 0;
      if (cur->nxt[idx]->prefix_cnt == 0) return 0;
      cur = cur->nxt[idx];
    }
    // return cur->word_cnt or cur->prefix_cnt;;
  }
  void del(node* cur) {
    if (!cur) return;
    for (int i = 0; i < 26; i++) {
        if (cur->nxt[i]) del(cur->nxt[i]);
    }
    delete cur;
  }
};
