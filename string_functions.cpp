#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 1;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i] += 1;
        if(i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
    vector<int> lps(n);
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j && s[j] != s[i]) j = lps[j - 1];
        if(s[j] == s[i]) j += 1;
        lps[i] = j;
    }
    for(int i : z) cout << i << ' ';
    cout << '\n';
    for(int i : lps) cout << i << ' ';
    cout << '\n';
}
