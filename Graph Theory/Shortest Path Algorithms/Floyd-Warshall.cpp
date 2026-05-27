const int INF = 1e18;         
const int N   = 505;
int d[N][N], p[N][N];
void floyd_warshall(int n) {
    for (int i = 1; i <= n; ++i) d[i][i] = 0, p[i][i] = i;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j) {
                if (d[k][j] == INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k]; 
                }
            }
        }
    for (int k = 1; k <= n; ++k) {
        if (d[k][k] >= 0) continue;                 
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF) d[i][j] = -INF;
            }
        }   
    }
}
