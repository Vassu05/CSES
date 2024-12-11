#include <bits/stdc++.h>
using namespace std;
#define double long double
double a, b;
double ans;
int main(){
    int n, k; cin >> n >> k;
    ans = 0.0;
    // sum of expected values for each of k values
    for(int i = 1; i <= k; i++) {
        a = b = 1.0;
        // probability of i being maximum is (i / n) ^ k - ((i - 1) / k) ^ k
        for(int j = 1; j <= n; j++) {
            a *= (double)i / k;
            b *= (double)(i - 1) / k;
        }
        ans += (double)i * (a - b);
    }
    ans *= 1e10;
    ans = llround(ans);
    ans /= 1e3;
    if((long long)ans == ans) {
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
}
