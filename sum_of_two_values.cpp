#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n); 
    for(int &i : a) cin >> i;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int p, int q) {
        return a[p] < a[q];
    });
    int j = n - 1;
    for(int i = 0; i < n; i++) {
        while(j >= 0 && a[ord[i]] + a[ord[j]] > x) j -= 1;
        if(j >= 0 && a[ord[i]] + a[ord[j]] == x && ord[i] != ord[j]) {
            cout << ord[i] + 1 << ' ' << ord[j] + 1 << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
