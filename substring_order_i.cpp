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

vector<int> lcp_array(string s, vector<int> suf) {
    int n = s.length();
    vector<int> rank(n), lcp(n);
    for(int i = 0; i < n; i++) {
        rank[suf[i]] = i;
    }
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
    int n = s.length();
    auto suf = suffix_array(s);
    auto lcp = lcp_array(s, suf);
    long long k; cin >> k;
    --k;
    for(int i = 0; i < n; i++) {
        int len = n - suf[i];
        len -= lcp[i];
        if(k < len) {
            int size = lcp[i] + 1;
            size += k;
            cout << s.substr(suf[i], size) << '\n';
            return 0;
        }
        k -= len;
    }
}
