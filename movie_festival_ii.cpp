#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    multiset<int> st;
    vector<pair<int,int>> a;
    vector<int> b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.emplace_back(x, i);
        a.emplace_back(y, -i);
        b[i] = x, c[i] = y;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(auto [x, y] : a) {
        if(y > 0) {
            if((int)st.size() < k) {
                st.insert(c[y]);
            }
            else {
                if(*(--st.end()) > c[y]) {
                    st.erase(--st.end());
                    st.insert(c[y]);
                }
            }
        }
        else {
            if(st.count(x)) {
                st.erase(st.find(x));
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}
