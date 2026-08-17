vector<int> bct[2 * N];
int bct_id[N];
void build_bct(int n) {
    int bct_nodes = bcc_cnt; 
    for (int i = 1; i <= n; i++) {
        if (cutpoint[i]) {
            bct_id[i] = ++bct_nodes;
        }
    }
    for (int i = 0; i < bcc_cnt; i++) {
        int bcc_node = i + 1;
        for (int u : bccs[i]) {
            if (cutpoint[u]) {
                int cut = bct_id[u];
                bct[bcc_node].push_back(cut);
                bct[cut].push_back(bcc_node);
            } 
            else bct_id[u] = bcc_node;
        }
    }
}
