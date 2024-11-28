#include <bits/stdc++.h>
using namespace std;
int n, k1, k2;
const int N = 200200;
vector<int> g[N];

int give(deque<int> &d, int idx) {
    if(idx < 0) return 0;
    if(idx + 1 >= d.size()) return d[0];
    else return d[0] - d[idx + 1];
}

long long combine(deque<int> &d1, deque<int> &d2) {
    if(d1.size() < d2.size()) swap(d1, d2);
    d2.push_back(0);
    long long ans = 0;
    for(int i = 0; i < (int)d2.size() - 1; i++) {
        int now = d2[i] - d2[i + 1];
        ans += 1LL * now * (give(d1, k2 - i) - give(d1, k1 - i - 1));
    }
    for(int i = 0; i < d2.size() - 1; i++) d1[i] += d2[i];
    return ans;
}

int main(){
    cin >> n >> k1 >> k2;
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    long long ans = 0;

    auto dfs = [&](auto self, int x, int y) -> deque<int> {
        deque<int> d = { 1 };
        for(auto it : g[x]) if(it != y) {
            deque<int> temp = self(self, it, x);
            temp.push_front(temp.front());
            ans += combine(d, temp);
        }
        return d;
    };

    dfs(dfs, 0, 0);

    cout << ans << '\n';
}
