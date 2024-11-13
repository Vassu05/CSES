#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.emplace_back(x, 1);
        a.emplace_back(y, -1);
    }
    sort(a.begin(), a.end());
    int count = 0, ans = 0;
    for(auto [x, y] : a) {
        if(y == 1) count += 1;
        else count -= 1;
        ans = max(ans, count);
    }
    cout << ans << '\n';
}
