#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // identify the pattern of grundy numbers for x number of sticks in a heap
        // 0 1 2 3 0 1 2 3 0 1 2 3 
        int x = 0;
        for(int i = 0; i < n; i++) {
            int sz; cin >> sz;
            x ^= sz % 4;
        }
        cout << (x ? "first" : "second") << '\n';
    }
}
