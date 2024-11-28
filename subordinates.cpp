#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        g[--x].push_back(i);
    }
    vector<int> ans(n);
    auto dfs = [&](auto self, int x) -> int {
        for(auto it : g[x]) ans[x] += self(self, it);
        return ans[x] + 1;
    }; dfs(dfs, 0);

    for(int &i : ans) cout << i << ' '; cout << '\n';
}
