#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> arr(n + 1); vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++) { 
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    int ans = -1e17;
    multiset<int> st;

    for(int i = 1; i <= n; i++) {
        if(i - a >= 0) st.insert(pre[i - a]);

        if(!st.empty()) {
            ans = max(ans, pre[i] - *st.begin());
        }

        if(i - b >= 0) st.erase(st.find(pre[i - b]));
    }

    cout << ans << '\n';
}
