#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int xx, int yy) { return a[xx] < a[yy]; });
    for(int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while(l < r) {
            int sum = a[ord[i]] + a[ord[l]] + a[ord[r]];
            if(sum == x) {
                cout << ord[i] + 1 << ' ' << ord[l] + 1 << ' ' << ord[r] + 1 << '\n';
                return 0;
            }
            else if(sum < x) {
                l += 1;
            }
            else r -= 1;
        }
    }
    cout << "IMPOSSIBLE\n";
}
