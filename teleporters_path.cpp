#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n), out(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        in[y] += 1;
        out[x] += 1;
    }
    bool possible = true;
    for(int i = 1; i < n - 1; i++) {
        possible &= in[i] == out[i];
    }
    possible &= in[0] + 1 == out[0];
    possible &= in[n - 1] - 1 == out[n - 1];
    if(!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    stack<int> st;
    st.push(0);
    while(!st.empty()) {
        int x = st.top();
        if(g[x].empty()) {
            ans.push_back(x);
            st.pop();
        }
        else {
            int y = g[x].back();
            g[x].pop_back();
            st.push(y);
        }
    }
    if(ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i + 1 << ' ';
    cout << '\n';
}
