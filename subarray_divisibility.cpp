#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    map<long long,int> mp;
    mp[0] = 1;
    long long sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        sum += y;
        sum %= n;
        sum = (sum + n) % n;
        ans += mp[sum];
        mp[sum] += 1;
    }
    cout << ans << '\n';
}
