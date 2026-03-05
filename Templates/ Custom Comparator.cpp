bool cmp(const pair<int,int>&p1, const pair<int,int>&p2) {
    if(p1.first<p2.first) return 1;
    if(p1.first==p2.first) return p1.second>p2.second;
    return 0;
}
