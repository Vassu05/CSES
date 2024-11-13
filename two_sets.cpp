#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    long long sum = 1LL * n * (n + 1) / 2;
    if(sum % 2 == 1) {
        cout << "NO\n";
        return 0;
    }
    vector<int> first, second;
    sum /= 2;
    for(int i = n; i >= 1; i--) {
        if(sum - i >= 0) {
            first.push_back(i);
            sum -= i;
        }
        else {
            second.push_back(i);
        }
    }
    cout << "YES\n";
    cout << first.size() << '\n';
    for(int i : first) cout << i << ' ';
    cout << '\n';
    cout << second.size() << '\n';
    for(int i : second) cout << i << ' ';
    cout << '\n';
}
