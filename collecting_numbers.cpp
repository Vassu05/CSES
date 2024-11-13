#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        --x;
        a[x] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(a[i - 1] > a[i]) ans += 1;
    }
    cout << ans << '\n';
}
