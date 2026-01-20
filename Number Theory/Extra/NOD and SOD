pair<int, int> NOD_and_SOD(int n) {
    pair<int, int> ans;
    ans.first = 1;
    ans.second = 1;
    while (n > 1) {
        int p = spf[n];
        int count = 0;
        int sum = 1, factor = 1;
        while (n % p == 0) {
            n /= p;
            count++;
            factor *= p;
            sum += factor;
        }
        ans.first *= (count + 1);
        ans.second *= sum;
    }
    return ans;
}
