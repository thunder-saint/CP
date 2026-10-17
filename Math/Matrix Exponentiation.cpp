struct Matrix {
    int r, c;
    vector<vector<int>> m;
    Matrix(int r,int c):r(r),c(c),m(r,vector<int>(c,0)){} //
    static Matrix identity(int n) {
        Matrix M(n, n);
        for (int i = 0; i < n; i++) M.m[i][i] = 1; //
        return M;
    }
    Matrix operator + (const Matrix &b) const {
        assert(r == b.r && c == b.c);
        Matrix ans(r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans.m[i][j] = m[i][j] + b.m[i][j];
                if (ans.m[i][j] >= MOD) ans.m[i][j] -= MOD;
            }
        }
        return ans;
    }
    Matrix operator - (const Matrix &b) const {
        assert(r == b.r && c == b.c);
        Matrix ans(r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans.m[i][j] = m[i][j] - b.m[i][j];
                if (ans.m[i][j] < 0) ans.m[i][j] += MOD;
            }
        }
        return ans;
    }
    Matrix operator * (const Matrix &x) const {
        assert(c == x.r);
        Matrix M(r, x.c);
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if(m[i][k] == 0) continue;//
                for (int j = 0; j < x.c; j++) {
                    if(x.m[k][j] == 0) continue;//
                    M.m[i][j]=(M.m[i][j]+m[i][k]*x.m[k][j])%MOD;
                }
            }
        }
        return M;
    }
    Matrix power(int p) const {
        assert(r == c);
        Matrix res = identity(r);
        Matrix base = *this;
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
    bool operator == (const Matrix& b) const { return m == b.m; }
    bool operator != (const Matrix& b) const { return m != b.m; }
};
