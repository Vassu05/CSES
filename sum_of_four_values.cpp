#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin >> n;
    int t; cin >> t;
    vector<int> a(n);
    map<int, vector<pair<int,int>>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            int sum = a[i] + a[j];
            for(auto [x, y] : mp[t - sum]) {
                if(x != i && y != i && x != j && y != j) {
                    cout << x + 1 << ' ' << y + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
                    return 0;
                }
            }
            mp[sum].emplace_back(i, j);
        }
    }
    cout << "IMPOSSIBLE\n";
}
