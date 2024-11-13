#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin >> n;
    int mx = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    if(mx > sum - mx) cout << 2 * mx << '\n';
    else cout << sum << '\n';
}
