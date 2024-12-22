#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s) {
    int n = s.length();
    vector<int> suf(n), val(n);
    for(int i = 0; i < n; i++) {
        suf[i] = i, val[i] = s[i];
    }
    for(int j = 1; j < n; j <<= 1) {
        auto comp = [&](int x, int y) -> bool {
            if(val[x] != val[y]) return val[x] < val[y];
            x += j;
            y += j;
            return (x < n && y < n) ? val[x] < val[y] : x > y;
        };
        sort(suf.begin(), suf.end(), comp);
        vector<int> temp(n);
        for(int i = 1; i < n; i++) {
            temp[i] = temp[i - 1] + comp(suf[i - 1], suf[i]);
        }
        for(int i = 0; i < n; i++) val[suf[i]] = temp[i];
    }
    return suf;
}

vector<int> construct_lcp(string s, vector<int> suf) {
    int n = suf.size();
    vector<int> rank(n), lcp(n);
    for(int i = 0; i < n; i++) {
        rank[suf[i]] = i;
    }
    // it's important to start from index 0, so that you can decrement h by 1
    // example:
    // s[0:n-1]
    // and suf[0:n-1] has a common prefix of length 3 in the sorted suffixes
    // we can surely say that suf[1:n-1] has a common prefix of length 2 in the sorted suffixes
    int h = 0;
    for(int i = 0; i < n; i++) {
        if(rank[i] == 0) continue;
        int idx = suf[rank[i] - 1];
        while(i + h < n && idx + h < n && s[i + h] == s[idx + h]) h++;
        lcp[rank[i]] = h;
        if(h > 0) h--;
    }
    return lcp;
}

int main(){
    string s; cin >> s;
    int n = s.size();
    auto suf = suffix_array(s);
    auto lcp = construct_lcp(s, suf);
    cout << 1LL * n * (n + 1) / 2 - accumulate(lcp.begin(), lcp.end(), 0LL) << '\n';
}
