#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long
const ll inf = 1e17;
const int N = 3001;
ll dp[N], a[N], pre[N], Left[N], cost[N][N], ndp[N];

void DnC(int l, int r, int optL, int optR) {
    if(l > r) return;
    int opt = optL;
    int mid = (l + r) / 2;
    ll &ans = ndp[mid];

    for(int i = optL; i <= min(mid, optR); i++) {
        if(ans > dp[i - 1] + cost[i][mid]) {
            ans = dp[i - 1] + cost[i][mid];
            opt = i;
        }
    }

    DnC(l, mid - 1, optL, opt);
    DnC(mid + 1, r, opt, optR);
}

int32_t main(){
    auto beg = high_resolution_clock::now();
    ios_base::sync_with_stdio(0); cin.tie(0);
    // dp[i][j] = minimum possible ans until i student with j schools
    // dp[x][j] = min(dp[x][j], dp[i][j - 1] + c[i + 1][x])
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for(int i = 1; i <= n; i++) Left[i] = Left[i - 1] + i * a[i];

    auto getCost = [&](int l, int r, int mid) -> ll {
        ll lCount = pre[mid - 1] - pre[l - 1];
        ll rCount = pre[r] - pre[mid];
        return lCount * mid - (Left[mid - 1] - Left[l - 1]) + (Left[r] - Left[mid]) - rCount * mid;
    };

    for(int i = 1; i <= n; i++) {
        int mid = i;
        for(int j = i; j <= n; j++) {
            while(mid < j && getCost(i, j, mid) > getCost(i, j, mid + 1)) mid += 1;
            cost[i][j] = getCost(i, j, mid);
        }
    }

    for(int i = 0; i <= n; i++) dp[i] = ndp[i] = inf;

    dp[0] = 0;

    for(int i = 1; i <= k; i++) { 
        DnC(1, n, 1, n);
        for(int j = 0; j <= n; j++) dp[j] = ndp[j], ndp[j] = inf;
    }

    cout << dp[n] << '\n';
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - beg);
    cerr << "Elapsed Time: " << duration.count() / 1000000.0;
}
