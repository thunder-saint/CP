#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << ":\n", x
#else
#define dbg(x)
#endif

/* -------- MATRIX / DP DEBUG -------- */

template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& mat){
    for(const auto &row : mat){
        for(const auto &x : row)
            os << setw(5) << x << " ";
        os << "\n";
    }
    return os;
}

/* -------- GRAPH DEBUG -------- */

template<typename T>
void debug_graph(const vector<vector<T>>& g){
    cerr << "\n";
    for(int i = 0; i < (int)g.size(); i++){
        cerr << i << " -> ";
        for(auto v : g[i]) cerr << v << " ";
        cerr << "\n";
    }
    cerr << "\n";
}

/* -------- BITMASK DEBUG -------- */

string bits(long long x){
    string s = "";
    for(int i = 31; i >= 0; i--)
        s += ((x >> i) & 1) + '0';
    return s;
}
