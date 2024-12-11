#include <bits/stdc++.h>
using namespace std;
int main(){
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        auto get = [&](auto self, int x, int what) {
            if(x == 1) return x;
            if(what == 0) {
                int rem = x / 2;
                if(k <= rem) {
                    return 2 * k;
                }
                else {
                    k -= rem;
                    return 2 * self(self, x - rem, x % 2) - 1;
                }
            }
            else {
                int rem = (x + 1) / 2;
                if(k <= rem) {
                    return 2 * k - 1;
                }
                else {
                    k -= rem;
                    return 2 * self(self, x - rem, !(x % 2));
                }
            }
        };
        cout << get(get, n, 0) << '\n';
    }
}
