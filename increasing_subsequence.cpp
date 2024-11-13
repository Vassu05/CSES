#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<int> b;
    for(int i = 0; i < n; i++) {
        if (b.empty() || b.back() < a[i]) b.push_back(a[i]);
        else *lower_bound(b.begin(), b.end(), a[i]) = a[i];
    }
    cout << b.size() << '\n';
}
