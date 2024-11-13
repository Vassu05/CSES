#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    long long ans = -1e9, mx = 0;
    for(int i : a) {
        mx += i;
        ans = max(ans, mx);
        mx = max(mx, 0LL);
    }
    cout << ans << '\n';
}
