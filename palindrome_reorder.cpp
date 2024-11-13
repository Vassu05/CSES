#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(){
    string s; cin >> s;
    for(char c : s) a[c - 'A'] += 1;
    string ans = "";
    int now = -1;
    for(int i = 0; i < 26; i++) {
        int c = a[i] / 2;
        while(c--) {
            ans += char(i + 'A');
        }
        if (a[i] & 1) {
            if(now != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            now = i;
        }
    }
    cout << ans;
    if(now != -1) cout << char(now + 'A');
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
