#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    multiset<int> st;
    for(int i : a) st.insert(i);
    for(int i = 0; i < m; i++) {
        auto it = st.upper_bound(b[i]);
        if(it != st.begin()) {
            --it;
            cout << *it << '\n';
            st.erase(it);
        }
        else cout << -1 << '\n';
    }
}
