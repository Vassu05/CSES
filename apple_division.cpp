#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> p(n);
    for(int &i : p) cin >> i;
    long long ans = 1e17, total_sum = 0;
    for(int i : p) total_sum += i;
    for(int i = 0; i < 1 << n; i++) {
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) sum += p[j];
        }
        ans = min(ans, abs(total_sum - sum - sum));
    }
    cout << ans << '\n';
}
