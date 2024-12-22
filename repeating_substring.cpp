#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_arrays(string s) {
    int n = s.length();
    vector<int> suf(n), val(n);
    for(int i = 0; i < n; i++) {
        suf[i] = i, val[i] = s[i];
    }
    for(int j = 1; j < n; j <<= 1) {

        auto comp = [&](int x, int y) -> bool {
            if(val[x] != val[y]) return val[x] < val[y];
            x += j, y += j;
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
    int n = s.length();
    vector<int> rank(n), lcp(n);
    for(int i = 0; i < n; i++) rank[suf[i]] = i;
    int h = 0;
    for(int i = 0; i < n; i++) {
        if(rank[i] == 0) continue;
        int idx = suf[rank[i] - 1];
        while(i + h < n && idx + h < n && s[i + h] == s[idx + h]) h += 1;
        lcp[rank[i]] = h;
        if(h > 0) h -= 1;
    }
    return lcp;
}

int main(){
    string s; cin >> s;
    auto suf = suffix_arrays(s);
    auto lcp = construct_lcp(s, suf);
    int idx = 0, len = 0;
    for(int i = 1; i < (int)s.length(); i++) {
        if(lcp[i] > len) {
            len = lcp[i];
            idx = suf[i];
        }
    }
    cout << (len == 0 ? "-1": s.substr(idx, len)) << '\n';
}
