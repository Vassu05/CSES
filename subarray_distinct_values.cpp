#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int j = 0, cnt = 0;
    map<int,int> mp;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        while(j < n && cnt <= k) {
            if(mp[a[j]] == 0 && cnt == k) break;
            if(++mp[a[j]] == 1) cnt += 1;
            j += 1;
        }
        ans += j - i;
        if(!--mp[a[i]]) cnt -= 1;
    }
    cout << ans << '\n';
}
