#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    map<char, Node*> mp;
    int count;
    Node() {
        count = 0;
    }
};

int main(){
    string s; cin >> s;
    int k; cin >> k;
    Node* root = new Node();
    auto update = [&](string t) -> void {
        int m = t.length();
        Node* temp = root;
        for(int j = 0; j < m; j++) {
            if(!temp->mp[t[j]]) temp->mp[t[j]] = new Node();
            temp = temp->mp[t[j]];
        }
        temp->count += 1;
    };
    for(int i = 0; i < k; i++) {
        string t; cin >> t;
        update(t);
    }
    int mod = 1e9 + 7;
    int n = s.length();

    vector<int> dp(n + 1);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        Node* temp = root;
        int j = i;
        while(j < n && temp != NULL) {
            if(!temp->mp[s[j]]) break;
            temp = temp->mp[s[j]];
            j += 1;
            dp[j] = (dp[j] + 1LL * dp[i] * temp->count % mod) % mod;
        }
    }

    cout << dp[n] << '\n';
}
