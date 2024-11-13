#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(auto &s : a) cin >> s;
    auto dfs = [&](auto self, int x, int y) -> void {
        if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#') return;
        a[x][y] = '#';
        self(self, x - 1, y);
        self(self, x + 1, y);
        self(self, x, y - 1);
        self(self, x, y + 1);
    };
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(a[i][j] == '.') {
        ans += 1;
        dfs(dfs, i, j);
    }
    cout << ans << '\n';
}
