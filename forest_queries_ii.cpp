#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n, vector<int> (n));

    vector<vector<int>> fen(n + 1, vector<int> (n + 1, 0));

    auto update = [&](int x, int y, int val) {
        for(int i = x + 1; i <= n; i += i & -i) for(int j = y + 1; j <= n; j += j & -j) {
            fen[i][j] += val;
        }
    };

    auto get = [&](int x, int y) {
        int ans = 0;
        for(int i = x + 1; i > 0; i -= i & -i) for(int j = y + 1; j > 0; j -= j & -j) {
            ans += fen[i][j];
        }
        return ans;
    };

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        char c; cin >> c;
        a[i][j] = (c == '*');
        update(i, j, a[i][j]);
    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int x, y; cin >> x >> y;
            --x, --y;
            update(x, y, (a[x][y] == 1 ? -1 : 1));
            a[x][y] = 1 - a[x][y];
        }
        else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            --x1, --y1, --x2, --y2;
            int ans = get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
            cout << ans << '\n';
        }
    }
}
