#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    s += s;
    int n = s.length();
    vector<int> pre(n);
    int prime = 131;
    int now = 1;
    int mod = 1e9 + 7;
    for(int i = 0; i < n; i++) {
        pre[i] = i > 0 ? pre[i - 1] : 0;
        pre[i] = (pre[i] + 1LL * (s[i] - 'a') * now % mod) % mod;
        now = 1LL * now * prime % mod;
    }
    auto power = [&](int a, int b) -> int {
        int ans = 1;
        for(; b; b >>= 1, a = 1LL * a * a % mod) if(b & 1) ans = 1LL * ans * a % mod;
        return ans;
    };
    int prime_inv = power(prime, mod - 2);
    vector<int> store(n + 1);
    store[0] = 1;
    for(int i = 1; i <= n; i++) store[i] = 1LL * store[i - 1] * prime_inv % mod;
    auto give = [&](int l, int r) -> int {
        int now = pre[r];
        if(l > 0) now -= pre[l - 1];
        now = (now + mod) % mod;
        now = 1LL * now * store[l] % mod;
        return now;
    };

    int ans = 0;

    for(int i = 1; i < n / 2; i++) {
        int l = 0, r = n / 2 - 1;
        while(l <= r) {
            int mid = (l + r + 1) / 2;
            if(give(i, i + mid) == give(ans, ans + mid)) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(s[i + l] < s[ans + l]) ans = i;
    }

    cout << s.substr(ans, n / 2) << '\n';
}
