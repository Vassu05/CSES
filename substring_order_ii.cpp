#include <bits/stdc++.h>
#define int long long
using namespace std;

class Suffix_Automaton {
    public:
    vector<map<char,int>> edges;
    vector<int> link;
    vector<int> length;
    vector<int> cnt; // number of suffixes from state i 
    vector<int> dp; // number of substrings from state i
    int last;

    Suffix_Automaton(string s) {
        last = 0;
        edges.push_back(map<char, int> ());
        link.push_back(-1);
        length.push_back(0);
        cnt.push_back(0);
        int n = s.length();

        for(int i = 0; i < n; i++) {
            edges.push_back(map<char, int> ());
            link.push_back(0);
            length.push_back(i + 1);
            cnt.push_back(1);

            int r = edges.size() - 1;
            int p = last;

            while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
                edges[p][s[i]] = r;
                p = link[p];
            }

            if(p != -1) {
                int temp = edges[p][s[i]];
                if(length[temp] == length[p] + 1) {
                    link[r] = temp;
                }
                else {
                    edges.push_back(edges[temp]);
                    length.push_back(length[p] + 1);
                    link.push_back(link[temp]);
                    cnt.push_back(0);

                    int ntemp = edges.size() - 1;
                    link[temp] = ntemp;
                    link[r] = ntemp;

                    while(p >= 0 && edges[p][s[i]] == temp) {
                        edges[p][s[i]] = ntemp;
                        p = link[p];
                    }
                }
            }
            last = r;
        }
    }

    void calc(int x = 0) {
        if(dp[x] != -1) return;
        dp[x] = cnt[x];
        for(auto [c, v] : edges[x]) {
            calc(v);
            dp[x] += dp[v];
        }
    }

    void update_dp() {
        int n = length.size();
        dp = vector<int> (n, -1);
        vector<vector<int>> state_by_len(n);
        for(int i = 0; i < n; i++) {
            state_by_len[length[i]].push_back(i);
        }

        for(int i = n - 1; i >= 0; i--) {
            for(auto j : state_by_len[i]) if(link[j] != -1) {
                cnt[link[j]] += cnt[j];
            }
        }

        calc(0);
    }
};

int32_t main(){
    string s; cin >> s;
    long long K; cin >> K;

    Suffix_Automaton suffix(s);
    suffix.update_dp();
    string ans = "";

    auto dfs = [&](auto self, int x, long long k) -> void {
        if(k < 0) return;
        for(auto [c, v] : suffix.edges[x]) {
            if(k >= suffix.dp[v]) k -= suffix.dp[v];
            else {
                ans += c;
                self(self, v, k - suffix.cnt[v]);
                return;
            }
        }
    };

    dfs(dfs, 0, K - 1);
    cout << ans << '\n';
}
