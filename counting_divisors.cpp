#include <bits/stdc++.h>
using namespace std;
int main(){
    const int N = 1e6 + 1;
    vector<int> div(N);
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) div[j] += 1;
    }
    int x, t; for(cin >> t; t--; ) {
        cin >> x;
        cout << div[x] << '\n';
    }
}
