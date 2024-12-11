#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int x = 0;
        // grundy number of each pile is ize of the pile itself
        for(int i = 0; i < n; i++) { 
            int sz; cin >> sz;
            x ^= sz;
        }
        cout << (x ? "first" : "second") << '\n';
    }
}
