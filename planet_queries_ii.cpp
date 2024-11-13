#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &i : a) cin >> i, --i;
    int LOG = 30;
    vector<vector<int>> p(n, vector<int> (LOG));
    for(int i = 0; i < n; i++) p[i][0] = a[i];
    for(int i = 1; i < LOG; i++) for(int j = 0; j < n; j++) p[j][i] = p[p[j][i - 1]][i - 1];
    vector<int> line(n, -1), circle(n, -1), vis(n, 0), par(n), dp(n), size(n);
    iota(par.begin(), par.end(), 0);
    int l = 0, c = 0;
    for(int i = 0; i < n; i++) if(!vis[i]) {
        int now = i;
        vector<int> curr;
        while(true) {
            if(vis[now]) break;
            curr.push_back(now);
            vis[now] = 1;
            now = a[now];
        }
        if(circle[now] != -1) {
            for(int j : curr) {
                line[j] = l;
            }
            l += 1;
            for(int j = (int)curr.size() - 2; j >= 0; j--) par[curr[j]] = par[curr[j + 1]], dp[curr[j]] = dp[curr[j + 1]] + 1;
        }
        else if(line[now] != -1) {
            for(int j : curr) {
                line[j] = line[now];
            }
            par[curr.back()] = par[now];
            dp[curr.back()] = dp[now] + 1;
            for(int j = (int)curr.size() - 2; j >= 0; j--) par[curr[j]] = par[curr[j + 1]], dp[curr[j]] = dp[curr[j + 1]] + 1;
        }
        else {
            // take care of circle
            int j = 0;
            while(curr[j] != now) j += 1;

            for(int k = j; k < (int)curr.size(); k++) circle[curr[k]] = c, par[curr[k]] = now;
            c += 1;

            size[now] = curr.size() - j;

            for(int k = j + 1; k < (int)curr.size(); k++) dp[curr[k]] = dp[curr[k - 1]] + 1;


            for(int k = 0; k < j; k++) line[curr[k]] = l;
            l += 1;

            for(int k = j - 2; k >= 0; k--) { 
                par[curr[k]] = par[curr[k + 1]], dp[curr[k]] = dp[curr[k + 1]] + 1;
            }
        }
    }


    while(q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        if (line[x] != -1 && line[y] != -1) {
                int dist = abs(dp[x] - dp[y]);
                for(int j = 0; j < LOG; j++) if(dist >> j & 1) x = p[x][j];
                cout << (x == y ? dist : -1) << '\n';
        }
        else if(line[x] != -1 && circle[y] != -1) {
            int cycle_start = a[par[x]];
            if(circle[y] != circle[cycle_start]) cout << -1 << '\n';
            else {
                int dist = dp[x] + 1;
                cout << dist + (dp[y] - dp[a[par[x]]] + size[par[y]]) % size[par[y]] << '\n';
            }
        }
        else if (circle[x] != -1 && circle[y] != -1) {
            if (circle[x] != circle[y]) cout << -1 << '\n';
            else {
                cout << (dp[y] - dp[x] + size[par[y]]) % size[par[y]] << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
    }
}
