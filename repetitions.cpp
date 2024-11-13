#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    int ans = 1;
    int c = 1;
    for(int i = 1; i < (int)s.size(); i++) {
        if(s[i] != s[i - 1]) c = 0;
        ans = max(ans, ++c);
    }
    cout << ans << '\n';
}
