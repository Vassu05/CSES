#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.emplace_back(x, i);
        a.emplace_back(y, -i);
        b[i] = x;
    }
    map<int,int> mp;
    int ans = 0;
    sort(a.begin(), a.end());
    for(auto [x, y] : a) {
        if(y < 0) {
            y = -y;
            int curr = mp[b[y]] + 1;
            ans = max(ans, curr);
            mp[x] = max(mp[x], curr);
        }
        else {
            mp[x] = max(mp[x], ans);
        }
    }
    cout << ans << '\n';
}
