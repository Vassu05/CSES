#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, n; cin >> x >> n;
    multiset<int> ans;
    set<int> st;
    st.insert(0);
    st.insert(x);
    ans.insert(x);

    for(int i = 0; i < n; i++) {
        int now; cin >> now;
        auto it = st.lower_bound(now);
        int mx = *it;
        int mn = *(--it);
        ans.erase(ans.find(mx - mn));
        ans.insert(mx - now);
        ans.insert(now - mn);
        st.insert(now);
        cout << *(--ans.end()) << ' ';
    }
    cout << '\n';
}
