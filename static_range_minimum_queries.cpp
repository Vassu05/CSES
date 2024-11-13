#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SparseTable {
    public:
    int n;
    static constexpr int LOG = 20;
    vector<vector<T>> dp;
    vector<int> power;
    void init() {
        dp = vector<vector<T>> (n + 1, vector<T> (LOG));
        power = vector<int> (n + 1);
    }
    int get(int x, int y) {
        return min(x, y);
    }
    void preProcess() {
        for(int i = 1; i < LOG; i++) {
            for(int j = 1; j <= n - (1 << i) + 1; j++) dp[j][i] = get(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
        power[1] = 0;
        for(int i = 2; i <= n; i++) power[i] = power[i / 2] + 1;
    }
    SparseTable(int a[], int _n) {
        n = _n;
        init();
        for(int i = 1; i <= n; i++) dp[i][0] = a[i];
        preProcess();
    }
    SparseTable(vector<int> a, int _n) {
        n = _n;
        init();
        for(int i = 1; i <= n; i++) dp[i][0] = a[i];
        preProcess();
    }
    SparseTable(vector<int> a) {
        n = a.size();
        init();
        for(int i = 0; i < n; i++) dp[i + 1][0] = a[i];
        preProcess();
    }
    int query(int l, int r) {
        int dist = r - l + 1;
        int p = power[dist];
        return get(dp[l][p], dp[r - (1 << p) + 1][p]);
    }
};

int main() {
    int n, q; cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    SparseTable<int> sparseTable(a, n);
    while(q--) {
        int l, r; cin >> l >> r;
        cout << sparseTable.query(l, r) << '\n';
    }
}