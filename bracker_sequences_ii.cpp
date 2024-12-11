#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
class Combinatorics {
    public:

    int _n, _mod;
    vector<int> fact, ifact;

    int power(int x, int y) {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % _mod) if(y & 1) {
            ans = 1LL * ans * x % _mod;
        }
        return ans;
    }

    void init() {
        fact = vector<int> (_n + 1);
        ifact = vector<int> (_n + 1);
        fact[0] = 1;
        for(int i = 1; i <= _n; i++) fact[i] = 1LL * fact[i - 1] * i % _mod;
        ifact[_n] = power(fact[_n], _mod - 2);
        for(int i = _n - 1; i >= 0; i--) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % _mod;
    }

    int nCr(int x, int y) {
        if(x < y || y < 0) return 0;
        int ans = 1LL * fact[x] * ifact[y] % mod * ifact[x - y] % _mod;
        return ans;
    }

    Combinatorics() {
        _n = 1e6 + 118;
        _mod = 1e9 + 7;
        init();
    }
    Combinatorics(int __n) {
        _n = __n;
        _mod = mod;
        init();
    }
    Combinatorics(int __n, int __mod) {
        _n = __n;
        _mod = __mod;
        init();
    }
}C;




int main(){
    int n; cin >> n;
    string s; cin >> s;
    if(n & 1) {
        cout << 0 << '\n';
        return 0;
    }
    int k = s.length();
    int open = 0;
    for(char c : s) {
        if(c == '(') open += 1;
        else { 
            open -= 1;
            n -= 2;
        }
        if(open < 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
    n -= 2 * open;
    n /= 2;

    // 2 * n + open choose n - 2 * n + open choose n - 1

    cout << (C.nCr(2 * n + open, n) - C.nCr(2 * n + open, n - 1) + mod) % mod;
}
