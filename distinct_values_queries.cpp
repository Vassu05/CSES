#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n), next(n, -1);
    for(int &i : a) cin >> i;
    map<int,int> mp;

    vector<int> fen(n + 1);

    auto update = [&](int i, int val) -> void {
        for(++i; i <= n; i += i & -i) {
            fen[i] += val;
        }
    };

    auto get = [&](int i) -> int {
        int sum = 0;
        for(++i; i > 0; i -= i & -i) {
            sum += fen[i];
        }
        return sum;
    };

    auto query = [&](int i, int j) -> int {
        return get(j) - get(i - 1);
    };

    for(int i = n - 1; i >= 0; i--) {
        if(mp.find(a[i]) != mp.end()) {
            next[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }

    for(auto it : mp) {
        update(it.second, 1);
    }

    vector<vector<pair<int,int>>> queries(n);
    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        queries[x].emplace_back(y, i);
    }

    vector<int> ans(q);

    for(int i = 0; i < n; i++) {
        for(auto [j, idx] : queries[i]) {
            ans[idx] = query(i, j);
        }

        if(next[i] != -1) {
            update(next[i], 1);
        }

    }

    for(int &i : ans) cout << i << ' ';
    cout << '\n';
}
