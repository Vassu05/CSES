#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);
    vector<int> ans;
    int prev = 1;
    while((int)st.size() > 0) {
        auto it = st.upper_bound(prev);
        if(it == st.end()) {
            it = st.upper_bound(0);
        }
        ans.push_back(*it);
        st.erase(it);
        if(st.size() == 0) break;
        it = st.upper_bound(prev);
        if(it == st.end()) {
            it = st.upper_bound(0);
        }
        prev = *it;
    }
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
