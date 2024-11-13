#include <bits/stdc++.h>
using namespace std;

int vis[7][7];

string s;
bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= 7 || y >= 7 || vis[x][y]) return false;
    return true;
}

int dfs(int x, int y, int idx) {
    if (x < 0 || y < 0 || x >= 7 || y >= 7 || vis[x][y]) return 0;
    if (idx == 48) return (x == 6 && y == 0);
    if(x == 6 && y == 0) return 0;

    if (!isValid(x - 1, y) && !isValid(x + 1, y) && isValid(x, y - 1) && isValid(x, y + 1)) return 0;
    if (!isValid(x, y - 1) && !isValid(x, y + 1) && isValid(x - 1, y) && isValid(x + 1, y)) return 0;

    int shouldNot = 0;

    if (x > 0 && y > 0 && y < 6 && vis[x - 1][y - 1] && vis[x - 1][y + 1] && !vis[x - 1][y]) shouldNot |= 2 | 4 | 8;
    if (x < 6 && y > 0 && y < 6 && vis[x + 1][y - 1] && vis[x + 1][y + 1] && !vis[x + 1][y]) shouldNot |= 1 | 4 | 8;
    if (y > 0 && x > 0 && x < 6 && vis[x + 1][y - 1] && vis[x - 1][y - 1] && !vis[x][y - 1]) shouldNot |= 1 | 2 | 8;
    if (y < 6 && x > 0 && x < 6 && vis[x - 1][y + 1] && vis[x + 1][y + 1] && !vis[x][y + 1]) shouldNot |= 1 | 2 | 4;

    int ans = 0;

    vis[x][y] = 1;

    if ((s[idx] == 'D' || s[idx] == '?') && !(shouldNot & 2)) {
        ans += dfs(x + 1, y, idx + 1);
    }
    if ((s[idx] == 'U' || s[idx] == '?') && !(shouldNot & 1)) {
        ans += dfs(x - 1, y, idx + 1);
    }
    if ((s[idx] == 'L' || s[idx] == '?') && !(shouldNot & 4)) {
        ans += dfs(x, y - 1, idx + 1);
    }
    if ((s[idx] == 'R' || s[idx] == '?') && !(shouldNot & 8)) {
        ans += dfs(x, y + 1, idx + 1);
    }

    vis[x][y] = 0;

    return ans;
}

int main(){
    for(int i =0 ; i < 7; i++) for(int j = 0; j < 7; j++) vis[i][j] = 0;
    cin >> s;
    cout << dfs(0, 0, 0) << '\n';
}
