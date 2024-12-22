#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string s) {
    int n = s.length();
    vector<int> lps(n);
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j && s[j] != s[i]) j = lps[j - 1];
        if(s[j] == s[i]) j += 1;
        lps[i] = j;
    }
    return lps;
}

int main(){
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> lps = kmp(t);
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while(j && s[i] != t[j]) j = lps[j - 1];
        if(s[i] == t[j]) j += 1;
        if(j == m) {
            ans += 1;
            j = lps[j - 1];
        }
    }
    cout << ans << '\n';
}
