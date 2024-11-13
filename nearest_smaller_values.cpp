#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    stack<pair<int,int>> st;
    st.emplace(0, -1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        while(!st.empty() && st.top().first >= x) st.pop();
        cout << st.top().second + 1 << ' ';
        st.emplace(x, i);
    }
    cout << '\n';
}
