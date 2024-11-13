#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int q; cin >> q;
    vector<int> count;
    count.push_back(0);
    count.push_back(9);
    for(int i = 2; i < 18; i++) {
        count.push_back(count.back() * 10);
    }
    for(int i = 1; i < 18; i++) count[i] *= i;
    while(q--) {
        int k; cin >> k;
        int now = 0;
        while(k > count[now]) {
            k -= count[now];
            now += 1;
        }
        int curr = pow(10, now - 1);
        curr += (k - 1) / now;
        cout << to_string(curr)[(k - 1) % now] << '\n';
    }
}
