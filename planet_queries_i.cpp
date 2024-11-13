#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    int LOG = 30;
    vector<vector<int>> par(n, vector<int> (LOG));
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        --x;
        par[i][0] = x;
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j < n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    while(q--) {
        int x, k; cin >> x >> k;
        --x;
        for(int i = 0; i < LOG; i++) if(k >> i & 1) x = par[x][i];
        cout << x + 1 << '\n';
    }
}
