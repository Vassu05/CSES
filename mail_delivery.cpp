#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    vector<int> deg(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[--x].emplace_back(--y, i);
        g[y].emplace_back(x, i);
        deg[x] += 1;
        deg[y] += 1;
    }
    bool possible = true;
    for(int i = 0; i < n; i++) {
        possible &= deg[i] % 2 == 0;
    }
    stack<int> st;
    vector<int> vis(m);
    vector<int> ans;
    st.push(0);
    while(!st.empty()) {
        int x = st.top();
        if(deg[x] == 0) {
            ans.push_back(x);
            st.pop();
        }
        else {
            while(vis[g[x].back().second]) g[x].pop_back();
            deg[g[x].back().first] -= 1;
            st.push(g[x].back().first);
            deg[x] -= 1;
            vis[g[x].back().second] = 1;
        }
    }
    if(!possible || (int)ans.size() < m + 1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for(int i : ans) cout << i + 1 << ' ';
        cout << '\n';
    }
}
