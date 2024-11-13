#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    auto print = [&](int x) -> void {
        for(int i = 0; i < n; i++) {
            cout << (x >> i & 1);
        }
        cout << '\n';
    };
    vector<vector<int>> a(1<<n);
    for(int i = 0; i < 1 << n; i++) {
        for(int j = 0; j < n; j++) {
            int ni = i ^ (1 << j);
            a[i].push_back(ni);
        }
    }
    int now = 0;
    vector<int> vis(1 << n);
    int cnt = 0;
    while(cnt < (1 << n)) {
        print(now);
        vis[now] = 1;
        cnt += 1;
        for(int j = 0; j < n; j++) {
            int next = now ^ (1 << j);
            if(!vis[next]) {
                now = next;
                break;
            }
        }
    }
}
