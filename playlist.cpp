#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int> mp;
    vector<int> a(n); for(int &i : a) cin >> i;
    int ans = 0, last = 0;
    for(int i = 0; i < n; i++) {
        if(mp.find(a[i]) != mp.end()) {
            ans = max(ans, i - last);
            while(last < mp[a[i]]) {
                mp.erase(a[last]);
                last += 1;
            }
            last += 1;
        }
        mp[a[i]] = i;
    }
    ans = max(ans, n - last);
    cout << ans << '\n';
}
