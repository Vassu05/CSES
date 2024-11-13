#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    vector<int> ans(n);
    int i = 0;
    for(int l = 2; l <= n; l += 2) ans[i++] = l;
    for(int r = 1; r <= n; r += 2) ans[i++] = r;
    for(int it : ans) cout << it << ' ';
    cout << '\n';
}
