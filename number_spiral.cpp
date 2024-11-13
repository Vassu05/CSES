#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin >> t;
    while(t--) {
        int x, y; cin >> x >> y;
        if (x > y) {
            if (x % 2 == 0) {
                int done = x * x;
                cout << done - y + 1 << '\n';
            }
            else {
                int done = (x - 1) * (x - 1);
                cout << done + y << '\n';
            }
        }
        else {
            if (y % 2 == 0) {
                int done = (y - 1) * (y - 1);
                cout << done + x << '\n';
            }
            else {
                int done = y * y;
                cout << done - x + 1 << '\n';
            }
        }
    }
}
