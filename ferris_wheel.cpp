#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    int l = 0, r = n;
    int ans = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        int left = mid, right = n - 1;
        int cnt = mid;
        bool poss = true;
        while(left <= right) {
            int now = a[left];
            if(left < right) now += a[right];
            if(now > x) {
                poss = false;
                break;
            }
            cnt += 1;
            left += 1;
            right -= 1;
        }
        if(poss) {
            r = mid - 1;
            ans = min(ans, cnt);
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}
