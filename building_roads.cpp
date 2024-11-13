#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    auto find = [&](auto self, int x) -> int { return par[x] == x ? x : par[x] = self(self, par[x]); };
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x = find(find, x - 1), y = find(find, y - 1);
        if(x != y) par[y] = x;
    }
    vector<int> a;
    for(int i = 0; i < n; i++) if(par[i] == i) a.push_back(i);
    cout << a.size() - 1 << '\n';
    for(int i = 1; i < (int)a.size(); i++) cout << a[i - 1] + 1 << ' ' << a[i] + 1 << '\n';
}
