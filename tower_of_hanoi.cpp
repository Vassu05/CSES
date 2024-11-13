#include <bits/stdc++.h>
using namespace std;
int main(){
    int total; cin >> total;
    vector<pair<int,int>> ans;
    auto dfs = [&](auto self, int n, int from, int use, int to) -> void {
        if(n == 1) {
            ans.emplace_back(from, to);
            return;
        }
        self(self, n - 1, from, to, use);
        ans.emplace_back(from, to);
        self(self, n - 1, use, from, to);
    };
    dfs(dfs, total, 1, 2, 3);
    cout << ans.size() << '\n';
    for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
}
