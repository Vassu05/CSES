#include <bits/stdc++.h>
using namespace std;
#define double long double
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    double ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 1; k <= a[j]; k++) {
                ans += (1.0 / a[j]) * (1.0 * min(k - 1, a[i]) / a[i]);
            }
        }
    }
    ans = ans * 1e15;
    ans = llround(ans);
    ans /= 1e8;
    if(((long long)ans) * 10 == (ans * 10)) {
        if((long long)ans % 10 == 5) {
            ans /= 10;
            ans = (long long)ans;
            if((long long)ans % 2 == 1) ans += 1;
        }
        else {
            ans = (long long)(ans / 10);
        }
        ans /= 1e6;
    }
    else {
        ans /= 1e7;
    }
    cout << fixed << setprecision(6) << ans << '\n';

    // the solution doesn't work in c++ because of some decimal storage crap, had to code in python
}
