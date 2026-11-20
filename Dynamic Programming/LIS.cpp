int LIS(const vector<int>& v) {
    vector<int> dp;
    for (int x : v) {
        auto it = lower_bound(dp.begin(), dp.end(), x); // upper_bound for non-decreasing
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    return dp.size();
}
