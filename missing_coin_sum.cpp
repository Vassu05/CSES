#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;

    sort(a.begin(), a.end());

    long long can = 0;

    for(int i : a) {
        if(can < i - 1) {
            break;
        }
        can += i;
    }

    cout << can + 1 << '\n';
}
