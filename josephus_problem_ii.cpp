#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    const int b = sqrt(n);
    vector<int> store(n / b + 1);
    vector<int> present(n + 2 * b + 1);
    for(int i = 1; i <= n; i++) present[i] = 1;
    for(int i = 1; i <= n; i++) {
        store[i / b] += 1;
    }
    int last = 1;
    for(int i = 1; i <= n; i++) {
        int req = k % (n - i  + 1);
        while(last % b != 0 && req - present[last] >= 0) {
            req -= present[last];
            last += 1;
        }
        if(last > n) last = 1;
        while(req - store[last / b] >= 0) {
            req -= store[last / b];
            if(last == 1) last += b - 1;
            else last += b;
            if(last > n) last = 1;
        }
        while(req - present[last] >= 0) {
            req -= present[last];
            last += 1;
            if(last > n) last = 1;
        }
        cout << last << ' ';
        store[last / b] -= 1;
        present[last] = 0;
        last += 1;
    }
    cout << '\n';
}
