#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 1e18;

class CHT {
    public:
    vector<int> m, c;
    int front;

    CHT() : front(0) {}

    void add(int s, int i) {
        if(m.size() > 0 && m.back() == s) {
            c.back() = min(c.back(), i);
            return;
        }
        while(m.size() >= 2) {
            int m1 = m.end()[-1], m2 = m.end()[-2];
            int c1 = c.end()[-1], c2 = c.end()[-2];
            // (i - c2) / (m2 - s) <= (c1 - c2) / (m2 - m1)
            if((i - c2) * (m2 - m1) <= (c1 - c2) * (m2 - s)) {
                m.pop_back();
                c.pop_back();
            }
            else break;
        }
        m.push_back(s);
        c.push_back(i);
    }

    int query(int x) {
        assert(front < m.size());
        // c[front] - c[front + 1] / (m[front + 1] - m[front])
        while(front < m.size() - 1 && x * (m[front] - m[front + 1]) > (c[front + 1] - c[front])) front += 1;
        return m[front] * x + c[front];
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    // dp[i][j] -> upto to ith element and j subarrays done
    // dp[x][j + 1] = min(dp[x][j + 1], dp[i][j] + (pre[x] - pre[i]) * (pre[x] - pre[i]))
    // dp[x][j + 1] = min(dp[x][j + 1], dp[i][j] + pre[i] * pre[i] + pre[x] * pre[x] - 2 * pre[x] * pre[i]; 

    vector<CHT> dp(k);
    dp[0].add(0, 0);
    int pre = 0, ans = 1e18;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pre += x;
        for(int j = min(i, k - 2); j >= 0; j--) {
            int curr = pre * pre + dp[j].query(pre);
            dp[j + 1].add( -2 * pre, curr + pre * pre);
        }
    }

    cout << dp[k - 1].query(pre) + pre * pre << '\n';
}
