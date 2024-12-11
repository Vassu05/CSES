#include <bits/stdc++.h>
using namespace std;

class Combinatorics {
    public:
    int n;
    int mod;
    vector<int> fact;
    vector<int> ifact;
    Combinatorics() {
        n = 1e6 + 118;
        mod = 1e9 + 7;
        fact = vector<int> (n);
        ifact = vector<int> (n);
        init();
    }
    Combinatorics(int _n, int _mod = 1e9 + 7) {
        n = _n + 1;
        mod = _mod;
        fact = vector<int> (n);
        ifact = vector<int> (n);
        init();
    }
    int power(int x, int y) {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    }
    void init() {
        fact[0] = 1;
        for(int i = 1; i < n; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
        ifact[n - 1] = power(fact[n - 1], mod - 2);
        for(int i = n - 2; i >= 0; i--) ifact[i] = 1LL* ifact[i + 1] * (i + 1) % mod;
    }
    int ncr(int x, int y) {
        if(x < y || y < 0) return 0;
        if(x >= n || y >= n) return 0;
        return 1LL * fact[x] * ifact[y] % mod * ifact[x - y] % mod;
    }
};

int main(){
    int t; cin >> t;
    Combinatorics comb;
    while(t--) {
        int x, y; cin >> x >> y;
        cout << comb.ncr(x, y) << '\n';
    }
}
