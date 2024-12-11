#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    vector<int> a(26);
    for(char c : s) a[c - 'a'] += 1;
    int n = s.length(), mod = 1e9 + 7;
    vector<int> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };
    int ans = fact[n];
    for(int i = 0; i < 26; i++) {
        ans = 1LL * ans * power(fact[a[i]], mod - 2) % mod;
    }
    cout << ans << '\n';
}
