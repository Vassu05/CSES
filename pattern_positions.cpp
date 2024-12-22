#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s) {
    int n = s.length();
    vector<int> suf(n), pos(n);
    for(int i = 0; i < n; i++) {
        suf[i] = i;
        pos[i] = s[i];
    }
    for(int j = 1; j < n; j <<= 1) {
        // suf[i] -> store the index idx of subarray [idx...n - 1] where i is the sorted position of subarray s[idx:n-1]
        // pos[i] -> store the value of subarray [i...i + j - 1]
        auto comp = [&](int x, int y) -> bool {
            if(pos[x] != pos[y]) return pos[x] < pos[y];
            x += j, y += j;
            return (x < n && y < n) ? pos[x] < pos[y] : x > y;
        };
        sort(suf.begin(), suf.end(), comp);
        vector<int> temp(n);
        for(int i = 1; i < n; i++) {
            int now = 0;
            temp[i] = temp[i - 1] + (comp(suf[i - 1], suf[i]));
        }
        for(int i = 0; i < n; i++) {
            pos[suf[i]] = temp[i];
        }
    }
    return suf;
}

int main(){
    string s; cin >> s;
    int n = s.length();
    auto suf = suffix_array(s);

    int LOG = 20;

    vector<vector<int>> dp(n, vector<int> (LOG));

    for(int i = 0; i < n; i++) {
        dp[i][0] = suf[i];
    }

    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j <= n - (1 << i); j++) {
            dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }

    vector<int> power(n + 1);
    power[1] = 0;

    for(int i = 2; i <= n; i++) power[i] = power[i / 2] + 1;

    auto get = [&](int l, int r) -> int {
        int d = r - l + 1;
        int p = power[d];
        return min(dp[l][p], dp[r - (1 << p) + 1][p]);
    };

    int q; cin >> q;
    while(q--) {


        string t; cin >> t;
        int found1 = -1;
        int l = 0, r = n - 1;

        auto check = [&](int mid) -> int {
            int now = 0;
            for(int i = 0; i < (int)t.length(); i++) {
                if(i + suf[mid] >= n) {
                    now = 1;
                    break;
                }
                if(s[i + suf[mid]] > t[i]) {
                    now = -1;
                    break;
                }
                if(s[i + suf[mid]] < t[i]) {
                    now = 1;
                    break;
                }
            }
            return now;
        };

        while(l <= r) {
            int mid = (l + r) / 2;
            int now = check(mid);
            if(now == 0) {
                found1 = mid;
                r = mid - 1;
            }
            else if(now == 1) l = mid + 1;
            else r = mid - 1;
        }

        int found2 = -1;
        l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int now = check(mid);
            if(now == 0) {
                found2 = mid;
                l = mid + 1;
            }
            else if(now == 1) l = mid + 1;
            else r = mid - 1;
        }

        if(found1 == -1) {
            cout << -1 << '\n';
            continue;
        }

        cout << get(found1, found2) + 1 << '\n';
    }
}
