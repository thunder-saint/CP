const int inf = 1e18;         
const int N   = 505;
int d[N][N], nxt[N][N], par[N][N]; 
void init_graph(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = (i == j) ? 0 : inf;
            nxt[i][j] = (i == j) ? i : -1;
            par[i][j] = (i == j) ? i : -1;
        }
    }
}
void floyd_warshall(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] == inf) continue;
            for (int j = 1; j <= n; ++j) {
                if (d[k][j] == inf) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                    par[i][j] = par[k][j]; 
                }
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        if (d[k][k] >= 0) continue;                 
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] < inf && d[k][j] < inf) {
                    d[i][j] = -inf;
                }
            }
        }   
    }
}
