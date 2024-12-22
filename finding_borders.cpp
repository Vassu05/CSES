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
    string s; cin >> s;
    auto lps = kmp(s);
    int i = s.length() - 1;
    vector<int> ans;
    while(i > 0) {
        int x = lps[i];
        if(x == 0) break;
        ans.push_back(x);
        i = x - 1;
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
