#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    int LOG = 20;
    vector<vector<int>> par(n + 1, vector<int> (LOG));
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        par[i][0] = x;
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    while(q--) {
        int x, k; cin >> x >> k;
        for(int j = 0; j < LOG; j++) if(k >> j & 1) x = par[x][j];
        cout << (x == 0 ? -1 : x) << '\n';
    }
}
