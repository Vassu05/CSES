#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int l = *max_element(a.begin(), a.end()), r = 1e15;
    while(l < r) {
        int mid = (l + r) / 2;
        int count = 1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum + a[i] <= mid) {
                sum += a[i];
            }
            else {
                count += 1;
                sum = a[i];
            }
        }
        if(count <= k) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
}
