#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(auto &s : a) cin >> s;
    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>> (m, { -1, -1 }));
    auto bfs = [&](int x, int y) -> void {
        queue<pair<int,int>> q;
        q.emplace(x, y);
        a[x][y] = '#';
        while(!q.empty()) {
            tie(x, y) = q.front(); q.pop();
            for(int i = -1; i <= 1; i++) for(int j = -1; j <= 1; j++) if(abs(i) + abs(j) == 1) {
                int nx = x + i, ny = y + j;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#') continue;
                dp[nx][ny] = { x, y };
                a[nx][ny] = '#';
                q.emplace(nx, ny);
            }
        }
    };

    int sx = -1, sy = -1, dx = -1, dy = -1;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(a[i][j] == 'A') {
            sx = i, sy = j;
        }
        else if(a[i][j] == 'B') {
            dx = i, dy = j;
        }
    }
    auto get = [&](int x, int y) -> char {
        if(dp[x][y].first > x) return 'U';
        else if(dp[x][y].first < x) return 'D';
        else if(dp[x][y].second > y) return 'L';
        else return 'R';
    };
    bfs(sx, sy);
    string ans = "";
    while(dx != sx || dy != sy) {
        if(dx == -1 || dy == -1) {
            cout << "NO\n";
            return 0;
        }
        ans += get(dx, dy);
        tie(dx, dy) = dp[dx][dy];
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << '\n' << ans << '\n';
}
