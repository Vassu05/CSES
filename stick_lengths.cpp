#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL), leftSum = 0;
    long long ans = 1e17;

    for(int i = 0; i < n; i++) {
        long long left = 1LL * i * a[i] - leftSum;
        long long right = sum - leftSum - 1LL * (n - i) * a[i];
        assert(left >= 0 && right >= 0);
        ans = min(ans, left + right);
        leftSum += a[i];
    }

    cout << ans << '\n';
}
