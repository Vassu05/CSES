#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string s) {
    int n = s.length();
    vector<int> lps(n);
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j && s[j] != s[i]) j = lps[j - 1];
        if(s[j] == s[i]) j += 1;
        lps[i] = j;
    }
    return lps;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int m = s.length();
    auto lps = kmp(s);
    int mod = 1e9 + 7;
    vector<int> power(n + 1);
    power[0] = 1;
    for(int i = 1; i <= n; i++) power[i] = 1LL * power[i - 1] * 26 % mod;

    vector<vector<int>> dp(n, vector<int> (m, -1));

    auto dfs = [&](auto self, int x, int y) -> int {
        if(y >= m) return power[n - x];
        if(x >= n) return 0;
        int &ans = dp[x][y];
        if(~ans) return ans;
        ans = 0;
        for(int i = 0; i < 26; i++) {
            int temp = y;
            while(temp && (s[temp] - 'A') != i) temp = lps[temp - 1];
            if((s[temp] - 'A') == i) temp += 1;
            ans = (ans + self(self, x + 1, temp)) % mod;
        }
        return ans;
    };

    cout << dfs(dfs, 0, 0) << '\n';
}
