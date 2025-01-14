#include <iostream>
using namespace std;

const int N = 2e5;
int a[N];

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < k; j++) {
            a[i] <<= 1;
            a[i] += s[j] - '0';
        }
    }
    int ans = 30;
    for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) {
        ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
    }
    cout << ans << '\n';
}
