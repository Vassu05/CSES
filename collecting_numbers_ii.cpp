#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        --x;
        a[i] = x;
        b[x] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++) if(b[i - 1] > b[i]) ++ans;
    while(m--) {
        int x, y; cin >> x >> y;
        --x, --y;

        x = a[x], y = a[y];

        if(x && b[x - 1] > b[x]) --ans;
        if(y && b[y - 1] > b[y]) --ans;

        if(x < n - 1 && x != y - 1 && b[x] > b[x + 1]) --ans;
        if(y < n - 1 && y != x - 1 && b[y] > b[y + 1]) --ans;

        swap(a[b[x]], a[b[y]]);
        swap(b[x], b[y]);

        if(x && b[x - 1] > b[x]) ++ans;
        if(y && b[y - 1] > b[y]) ++ans;

        if(x < n - 1 && x != y - 1 && b[x] > b[x + 1]) ++ans;
        if(y < n - 1 && y != x - 1 && b[y] > b[y + 1]) ++ans;

        cout << ans << '\n';

    }
}
