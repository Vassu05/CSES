#include <bits/stdc++.h>
using namespace std;
int main(){
    const int n = 8;
    vector<string> a(n);
    for(auto &s : a) cin >> s;

    auto isPossible = [&](int i, int j) -> bool {
        if(a[i][j] == '*') return false;
        for(int x = 0; x < 8; x++) {
            if(a[i][x] == '#') return false;
            if(a[x][j] == '#') return false;
        }
        int x = i, y = j;
        while(x >= 0 && y >= 0) {
            if(a[x][y] == '#') return false;
            x -= 1;
            y -= 1;
        }
        x = i, y = j;
        while(x >= 0 && y < n) {
            if(a[x][y] == '#') return false;
            x -= 1;
            y += 1;
        }
        return true;
    };

    auto dfs = [&](auto self, int i, int j) {
        if(i == 8) return 1;
        if(j == 8) return 0;
        int ans = self(self, i, j + 1);
        if(isPossible(i, j)) {
            a[i][j] = '#';
            ans += self(self, i + 1, 0);
            a[i][j] = '.';
        }
        return ans;
    };
    cout << dfs(dfs, 0, 0) << '\n';
}
