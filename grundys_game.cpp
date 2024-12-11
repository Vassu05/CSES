#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    const int N = 2e3 + 1;
    vector<int> dp(N), a(N);
    dp[0] = dp[1] = dp[2] = 0;
    for(int i = 3; i < N; i++) {
        for(int j = 1; j < i; j++) if(2 * j != i) {
            int now = dp[j] ^ dp[i - j];
            if(now < N) a[now] = 1;
        }
        while(a[dp[i]]) dp[i] += 1;
        for(int j = 0; j < N; j++) a[j] = 0;
    }
    while(t--) {
        int n; cin >> n;
        cout << (n >= N || dp[n] ? "first\n" : "second\n");
    }
}
