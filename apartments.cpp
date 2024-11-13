#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(j < n && b[i] > a[j] + k) j += 1;
        if(b[i] < a[j] - k) continue;
        if(j < n) {
            ans += 1;
            j += 1;
        }
    }
    cout << ans << '\n';
}
