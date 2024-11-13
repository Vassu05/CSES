#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int l = 0, r = 1e18 + 1;
    while(l < r - 1) {
        int mid = (l + r) / 2;
        int temp = t;
        for(int i = 0; i < n; i++) {
            temp -= mid / a[i];
            if(temp <= 0) break;
        }
        if(temp <= 0) r = mid;
        else l = mid;
    }

    cout << r << '\n';
}
