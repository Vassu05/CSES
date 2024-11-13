#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    vector<int> b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.emplace_back(x, i);
        a.emplace_back(y, -i);
        b[i] = x, c[i] = y;
    }
    sort(a.begin(), a.end(), [&](auto x, auto y) {
        if(x.second > 0 && y.second > 0) {
            if(x.first == y.first) return c[x.second] > c[y.second];
            return x.first < y.first;
        }
        return x.first < y.first;
    });
    int mx = 0;
    vector<int> p(n + 1), q(n + 1);
    
    for(auto [x, y] : a) {
        if(y > 0) {
            if(c[y] <= mx) q[y] = 1;
            mx = max(c[y], mx);
        }
    }

    reverse(a.begin(), a.end());
    mx = 2e9;
    for(auto [x, y] : a) {
        if(y > 0) {
            if(c[y] >= mx) p[y] = 1;
            mx = min(mx, c[y]);
        }
    }

    for(int i = 1; i <= n; i++) cout << p[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << q[i] << ' ';
    cout << '\n';
}
