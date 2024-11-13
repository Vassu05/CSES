#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < n; j++) {
            int nj = i + a[j];
            if(nj <= x) {
                dp[nj] = min(dp[nj], dp[i] + 1);
            }
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
}
