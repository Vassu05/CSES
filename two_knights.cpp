#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> store = { 0, 0, 6, 28, 96, 252, 550, 1056 };
    for(int i = 1; i <= min(n, 7); i++) {
        cout << store[i] << '\n';
    }
    long long ans = 1056;
    for (int i = 8; i <= n; i++) {

        ans += 1LL * (i - 1) * (i - 1) * (2 * i - 1);
        ans += 1LL * (2 * i - 2) * (2 * i - 1) / 2;

        // 2 steps top and 1 step towards sides
        ans -= 1LL * 2 * (i - 2) * 2;
        ans -= 4;

        // 1 step top and 2 steps towards sides
        ans -= 1LL * 2 * (i - 4) * 2;
        ans -= 2;
        ans -= 2;

        cout << ans << '\n';
    }
}
