#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(r >= i)
        z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] += 1;
        if(i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
    return z;
}

int main(){
    string s; cin >> s;
    int n = s.length();
    auto z = z_function(s);
    for(int i = 0; i < n; i++) {
        if(i + z[i] >= n) {
            cout << i << ' ';
        }
    }
    cout << n << ' ';
    cout << '\n';
}
