#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string s) {
    int n = s.length();
    int l = 0, r = 1;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(i < r) {
            ans[i] = min(ans[l + (r - i)], r - i);
        }
        while(i - ans[i] >= 0 && i + ans[i] < n && s[i - ans[i]] == s[i + ans[i]]) ans[i] += 1;
        if(i + ans[i] > r) {
            l = i - ans[i];
            r = i + ans[i];
        }
    }
    return ans;
}

vector<int> manacher_even(string s) {
    int n = s.length();
    int l = 0, r = 1;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(i < r - 1) {
            ans[i] = min(ans[l + (r - (i + 1))], r - (i + 1));
        }
        while(i - ans[i] >= 0 && i + ans[i] + 1 < n && s[i - ans[i]] == s[i + ans[i] + 1]) ans[i] += 1;
        if(i + ans[i] > r) {
            l = i - ans[i];
            r = i + ans[i] + 1;
        }
    }
    return ans;
}

int main(){
    string s; cin >> s;
    vector<int> a = manacher_odd(s), b = manacher_even(s);
    int idx = 0, size = 1;
    for(int i = 0; i < s.length(); i++) {
        if(2 * a[i] - 1 > size) {
            size = 2 * a[i] - 1;
            idx = i - a[i] + 1;
        }
        if(2 * b[i] > size) {
            size = 2 * b[i];
            idx = i - b[i] + 1;
        }
    }
    cout << s.substr(idx, size) << '\n';
}
