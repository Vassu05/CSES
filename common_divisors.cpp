#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    const int N = 1e6 + 1;
    vector<int> count(N, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        count[x] += 1;
    }

    int ans = 1;

    for(int i = 2; i < N; i++) { 
        int c = 0;
        for(int j = i; j < N; j += i) c += count[j];
        if(c > 1) ans = i;
    }
    cout << ans << '\n';
}
