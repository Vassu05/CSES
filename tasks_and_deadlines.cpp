#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin >> n;
    vector<int> a(n), b(n), ord(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return (b[x] - a[x] + b[y] - (a[x] + a[y])) > (b[y] - a[y] + b[x] - (a[x] + a[y]));
    });

    int ans = 0;
    int now = 0;
    for(int i : ord) {
        int end = now + a[i];
        ans += b[i] - end;
        now = end;
    }
    cout << ans << '\n';
}
