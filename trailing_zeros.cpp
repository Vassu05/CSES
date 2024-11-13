#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int ans = 0;

    for (long long i = 5; i <= n; i *= 5) {
        ans += n / i;
    }

    cout << ans << '\n';
}
