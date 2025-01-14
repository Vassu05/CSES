#include <iostream>
#include<bitset>
#pragma GCC target("popcnt")
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    bitset<3000> b[n];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int cnt = (b[i] & b[j]).count();
            ans += 1LL * cnt * (cnt - 1) / 2;

        }
    }
    cout << ans;
}
