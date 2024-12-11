#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for(int &i : a) cin >> i;
    vector<int> ans(n + 1);
    vector<int> b(k + 1);
    for(int i = 1; i <= n; i++) {
        for(int j : a) {
            if(i - j >= 0 && ans[i - j] <= k) {
                b[ans[i - j]] = 1;
            }
        }
        for(int j = 0; j <= k; j++) {
            if(!b[j]) break;
            ans[i] += 1;
        }
        for(int j = 0; j <= k; j++) b[j] = 0;
        cout << (ans[i] ? "W" : "L");
    }
}
