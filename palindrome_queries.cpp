#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

template<typename T>
class Fenwick {
    public:
    int n;
    vector<T> fen;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        fen = vector<T> (n + 1);
    }
    void add(int i, T x) {
        for (++i; i <= n; i += (i & -i)) fen[i] = (fen[i] + x + mod) % mod;
    }
    T query(int i) {
        T ans = 0;
        for (++i; i > 0; i -= (i & -i)) ans = (ans + fen[i]) % mod;
        return ans;
    }
    T query(int l, int r) { return (query(r) - query(l - 1) + mod) % mod; }
};


int32_t main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    Fenwick<long long> pre(n), suf(n);


    int prime = 31;

    int mul = 1;

    for(int i = 0; i < n; i++) {
        int now = 1LL * mul * (s[i] - 'a') % mod;
        pre.add(i, now);
        mul = 1LL * mul * prime % mod;
    }

    mul = 1;

    for(int i = n - 1; i >= 0; i--) {
        int now = 1LL * mul * (s[i] - 'a') % mod;
        suf.add(i, now);
        mul = 1LL * mul * prime % mod;
    }

    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };

    vector<int> div(n + 1);
    div[0] = 1;
    int inv = power(prime, mod - 2) % mod;
    for(int i = 1; i <= n; i++) {
        div[i] = 1LL * div[i - 1] * inv % mod;
    }

    auto get = [&](int l, int r, bool dir) -> int {
        if(dir) {
            int diff = pre.query(l, r);
            diff = 1LL * diff * div[l] % mod;
            return diff;
        }
        else {
            int diff = suf.query(l, r);
            diff = 1LL * diff * div[n - 1 - r] % mod;
            return diff;
        }
    };

    auto isPalindrome = [&](int l, int r) -> bool {
        int left = get(l, r, true), right = get(l, r, false);
        return get(l, r, true) == get(l, r, false);
    };


    vector<int> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = 1LL * fact[i - 1] * prime % mod;

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int idx; char c; cin >> idx >> c;
            --idx;
            pre.add(idx, - fact[idx] * (s[idx] - 'a') % mod);
            suf.add(idx, - fact[n - idx - 1] * (s[idx] - 'a') % mod);
            s[idx] = c;
            pre.add(idx, fact[idx] * (s[idx] - 'a') % mod);
            suf.add(idx, fact[n - 1 - idx] * (s[idx] - 'a') % mod);
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << (isPalindrome(l, r) ? "YES\n" : "NO\n");
        }
    }
}
