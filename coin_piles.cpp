#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        if ((a + b) % 3) {
            cout << "NO\n";
            continue;
        }
        if(a > b) swap(a, b);
        for(int i = 29; i >= 0; i--) {
            long long rem_a = (1LL << i);
            long long rem_b = (1LL << i) * 2;
            if (a - rem_a <= b - rem_b && a >= rem_a && b >= rem_b) {
                a -= rem_a;
                b -= rem_b;
            }
        }

        cout << (a == b ? "YES\n" : "NO\n");
    }
}
