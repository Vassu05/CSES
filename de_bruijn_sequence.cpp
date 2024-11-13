#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    if(n == 1) {
        cout << "01\n";
        return 0;
    }
    int m = n - 1;
    vector<vector<int>> g(1 << m);
    for(int i = 0; i < 1 << m; i++) {
        int ni = (((1 << (m - 1)) - 1) & i);
        ni *= 2;
        g[i].emplace_back(ni);
        g[i].emplace_back(ni + 1);
    }
    stack<int> st;
    st.push(0);
    vector<int> ans;
    while(!st.empty()) {
        int x = st.top();
        if(g[x].empty()) {
            st.pop();
            ans.push_back(x);
        }
        else {
            int y = g[x].back();
            g[x].pop_back();
            st.push(y);
        }
    }
    ans.pop_back();
    for(int i : ans) cout << (i & 1);
    for(int i = 0; i < n - 1; i++) cout << 0;
    cout << '\n';
}
