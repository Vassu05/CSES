#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    map<long long,int> mp;
    mp[0] = 1;
    long long sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        sum += y;
        ans += mp[sum - x];
        mp[sum] += 1;
    }
    cout << ans << '\n';
}
