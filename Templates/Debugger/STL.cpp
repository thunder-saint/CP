template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")";}
template < typename T > ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
        os << it->first << " = " << it->second;
    }
    return os << "]";
}
template< typename T >
ostream &operator << ( ostream & os, queue<T> q){
    os << "[";
    while(!q.empty()){
        os << q.front() << ", ";
        q.pop();
    }
    return os << "]";
}
template< typename T >
ostream &operator << (ostream& os,  stack<T> s){
    os << "[";
    while(!s.empty()){
        os << s.top() << ", ";
        s.pop();
    }
    return os << "]";
}
template< typename T >
ostream &operator << (ostream& os, priority_queue<T> pq){
    os << "[";
    while(!pq.empty()){
        os << pq.top() << ", ";
        pq.pop();
    }
    return os << "]";
}
template< typename T >
ostream &operator<<(ostream &os, const vector<vector<T>> & mat){
    os << "\n";
    for(auto &row : mat){
        os << "[ ";
        for(auto &x : row) os << x << " ";
        os << "]\n";
    }
    return os;
}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {
    cerr << endl;
}
template <typename T> void faltu( T a[], int n ) { for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello> void faltu( T arg, const hello &... rest) {cerr << arg << ' '; faltu(rest...);
