#include <bits/stdc++.h>
using namespace std;


class TwoSat {
    public:
    int n;
    vector<vector<int>> g, rev;
    vector<int> comp;
    TwoSat(int _n) {
        n = _n;
        g.resize(2 * n + 1);
        rev.resize(2 * n + 1);
        comp = vector<int> (2 * n + 1, -1);
    }
    void addEdge(int x, int y) {
        if(x > n) { 
            g[x - n].push_back(y);
            rev[y].push_back(x - n);
        }
        else {
            g[x + n].push_back(y);
            rev[y].push_back(x + n);
        }
        if(y > n) {
            g[y - n].push_back(x);
            rev[x].push_back(y - n);
        }
        else {
            g[y + n].push_back(x);
            rev[x].push_back(y + n);
        }
    }
    bool isPossible() {
        vector<int> vis(2 * n + 1);
        vector<int> ord;
        auto dfs = [&](auto self, int x) -> void {
            vis[x] = 1;
            for(auto it : g[x]) if(!vis[it]) {
                self(self, it);
            }
            ord.push_back(x);
        };
        for(int i = 1; i <= 2 * n; i++) if(!vis[i]) {
            dfs(dfs, i);
        }
        int c = 1;
        reverse(ord.begin(), ord.end());
        auto dfs2 = [&](auto self, int x) -> void {
            comp[x] = c;
            for(auto it : rev[x]) if(comp[it] == -1) { 
                self(self, it);
            }
        };
        for(int i : ord) if(comp[i] == -1) {
            dfs2(dfs2, i);
            c += 1;
        }
        for(int i = 1; i <= n; i++) if(comp[i] == comp[i + n]) return false;
        return true;
    }

    vector<int> findAssignment() {
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; i++) ans[i] = comp[i] > comp[i + n];
        return ans;
    }
};




int main(){
    int n, m; cin >> m >> n;
    TwoSat sat(n);
    for(int i = 0; i < m; i++) {
        char c1, c2; int x, y;
        cin >> c1 >> x >> c2 >> y;
        if(c1 == '-') x += n;
        if(c2 == '-') y += n;
        sat.addEdge(x, y);
    }
    if(!sat.isPossible()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans = sat.findAssignment();
        for(int i = 1; i <= n; i++) {
            cout << (ans[i] ? '+' : '-') << ' ';
        }
        cout << '\n';
}
