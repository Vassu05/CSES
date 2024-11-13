#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> a;
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.emplace_back(x, -i);
        a.emplace_back(y, i);
    }
    sort(a.begin(), a.end());
    set<int> free;
    int c = 0;
    vector<int> ans(n + 1);
    for(auto [x, y] : a) {
        if(y < 0) {
            if(free.empty()) {
                ans[-y] = ++c;
            }
            else ans[-y] = *free.begin(), free.erase(free.begin());
        }
        else {
            free.insert(ans[y]);
        }
    }

    cout << c << '\n';
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
