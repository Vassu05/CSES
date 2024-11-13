#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a, b; cin >> a >> b;
    string s = to_string(a), t = to_string(b);
    vector<int> power(20);
    power[0] = 1;
    for(int i = 1; i <= 18; i++) power[i] = power[i - 1] * 9;
    int n = s.length(), m = t.length();
    int ans = 0;
    for(int i = n + 1; i < m; i++) {
        ans += power[i];
    }
    if(n == m) {
        int idx = 0;
        bool flag = false;
        while(idx < n && s[idx] == t[idx]) { 
            if(idx && s[idx] == s[idx - 1]) {
                flag = true;
                break;
            }
            idx += 1;
        }
        if(!flag) {
            if(idx == n) {
                ans += 1;
            }
            else {
                if(idx == 0 || (s[idx - 1] <= s[idx] || s[idx - 1] >= t[idx])) ans += (t[idx] - s[idx] - 1) * power[n - idx - 1];
                else ans += (t[idx] - s[idx] - 2) * power[n - idx - 1];
                for(int i = idx + 1; (idx == 0 || s[idx] != s[idx - 1]) && i <= n; i++) {
                    if(i == n) {
                        ans += 1;
                        break;
                    }
                    int prev = 10 - (s[i] - '0') - 1;
                    if(i && s[i] < s[i - 1]) prev -= 1;
                    ans += prev * power[n - i - 1];
                    if(i && s[i] == s[i - 1]) break;
                }
                for(int i = idx + 1; (idx == 0 || t[idx] != t[idx - 1]) && i <= m; i++) {
                    if(i == m) {
                        ans += 1;
                        break;
                    }
                    int prev = (i == 0 ? (t[i] - '0' - 1) : (t[i] - '0'));
                    if(i && t[i] > t[i - 1]) prev -= 1;
                    ans += prev * power[m - i - 1];
                    if(i && t[i] == t[i - 1]) break;
                }
            }
        }

    }
    else {
        for(int i = 0; i <= n; i++) {
            if(i == n) {
                ans += 1;
                break;
            }
            int prev = 10 - (s[i] - '0') - 1;
            if(i && s[i] < s[i - 1]) prev -= 1;
            ans += prev * power[n - i - 1];
            if(i && s[i] == s[i - 1])  break;
        }
        for(int i = 0; i <= m; i++) {
            if(i == m) {
                ans += 1;
                break;
            }
            int prev = (i == 0 ? (t[i] - '0' - 1) : (t[i] - '0'));
            if(i && t[i] > t[i - 1]) prev -= 1;
            ans += prev * power[m - i - 1];
            if(i && t[i] == t[i - 1]) break;
        }
    }

    cout << ans << '\n';
}
