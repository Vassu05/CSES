#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i, --i;
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        if(ans[i] == -1) {
            vector<int> curr;
            int now = i;
            while(true) {
                if(ans[now] != -1) break;
                ans[now] = 0;
                curr.push_back(now);
                now = a[now];
            }
            if(ans[now] > 0) {
                ans[curr.back()] = ans[now] + 1;
                for(int j = (int)curr.size() - 2; j >= 0; j--) ans[curr[j]] = ans[curr[j + 1]] + 1;
            }
            else {
                int j = 0;
                while(curr[j] != now) j += 1;
                for(int k = j; k < (int)curr.size(); k++) ans[curr[k]] = curr.size() - j;
                for(int k = j - 1; k >= 0; k--) ans[curr[k]] = ans[curr[k + 1]] + 1;
            }
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
