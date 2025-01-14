#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end());
    while((int)a.size() > 0 && a.back() > x) {
        a.pop_back();
        n--;
    }
    int upto = n / 2;
    vector<int> store;
    for(int i = 0; i < 1 << upto; i++) {
        long long sum = 0;
        for(int j = 0; j < upto && sum <= x; j++) if(i >> j & 1) {
            sum += a[j];
        }
        if(sum <= x)
        store.push_back(sum);
    }
    int rem = n - upto;
    reverse(a.begin(), a.end());
    long long ans = 0;
    vector<int> now;
    for(int i = 0; i < 1 << rem; i++) {
        long long sum = 0;
        for(int j = 0; j < rem && sum <= x; j++) if(i >> j & 1) {
            sum += a[j];
        }
        if(sum <= x)
        now.push_back(sum);
    }
    sort(now.begin(), now.end());
    for(int i : store) {
        auto l = lower_bound(now.begin(), now.end(), x - i);
        auto r = upper_bound(now.begin(), now.end(), x - i);
        ans += r - l;
    }

    cout << ans << '\n';
}
