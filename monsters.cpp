#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    queue<pair<int,int>> q;
    int you[N][N], monsters[N][N];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        you[i][j] = monsters[i][j] = 1e9;
    }
    int sx = -1, sy = -1;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(a[i][j] == 'A') sx = i, sy = j;
    }
    q.emplace(sx, sy);
    you[sx][sy] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = -1; i <= 1; i++) for(int j = -1; j <= 1; j++) if(abs(i) != abs(j)) {
            int nx = x + i, ny = y + j;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#') continue;
            if(you[nx][ny] <= you[x][y] + 1) continue;
            you[nx][ny] = you[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(a[i][j] == 'M') {
        q.emplace(i, j);
        monsters[i][j] = 0;
    }
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = -1; i <= 1; i++) for(int j = -1; j <= 1; j++) if(abs(i) != abs(j)) {
            int nx = x + i, ny = y + j;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#') continue;
            if(monsters[nx][ny] <= monsters[x][y] + 1) continue;
            monsters[nx][ny] = monsters[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    int gotx = -1, goty = -1;
    for(int i = 0; i < n; i++) {
        if(you[i][0] < monsters[i][0]) gotx = i, goty = 0;
        if(you[i][m - 1] < monsters[i][m - 1]) gotx = i, goty = m - 1;
    }
    for(int i = 0; i < m; i++) {
        if(you[0][i] < monsters[0][i]) gotx = 0, goty = i;
        if(you[n - 1][i] < monsters[n - 1][i]) gotx = n - 1, goty = i;
    }
    if(gotx == -1) {
        cout << "NO\n";
        return 0;
    }
    auto find = [&](int x, int y, int px, int py) -> char {
        if(x > px) return 'D';
        else if(x < px) return 'U';
        else if(y > py) return 'R';
        else return 'L';
    };
    cout << "YES\n";
    cout << you[gotx][goty] << '\n';
    string ans = "";
    while(gotx != sx || goty != sy) {
        int foundx = -1, foundy = -1;
        for(int i = -1; i <= 1; i++) for(int j = -1; j <= 1; j++) if(abs(i) != abs(j)) {
            int nx = gotx + i, ny = goty + j;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#') continue;
            if(you[nx][ny] == you[gotx][goty] - 1) {
                foundx = nx, foundy = ny;
            }
        }
        ans += find(gotx, goty, foundx, foundy);
        tie(gotx, goty) = tie(foundx, foundy);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
