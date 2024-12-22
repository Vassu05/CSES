#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s) {
    int n = s.length();
    vector<int> suf(n), rank(n);
    for(int i = 0; i < n; i++) {
        suf[i] = i, rank[i] = s[i];
    }

    for(int j = 1; j < n; j <<= 1) {
        auto comp = [&](int x, int y) -> bool {
            if(rank[x] != rank[y]) return rank[x] < rank[y];
            x += j, y += j;
            return (x < n && y < n) ? rank[x] < rank[y] : x > y;
        };
        sort(suf.begin(), suf.end(), comp);
        vector<int> temp(n);
        for(int i = 1; i < n; i++) {
            temp[i] = temp[i - 1] + comp(suf[i - 1], suf[i]);
        }
        for(int i = 0; i < n; i++) {
            rank[suf[i]] = temp[i];
        }
    }
    return suf;
}

int main(){
    string s; cin >> s;
    int n = s.length();

    auto suf = suffix_array(s);
    int q; cin >> q;
    while(q--) {
        string t; cin >> t;

        auto check = [&](int mid) -> int {
            for(int i = 0; i < (int)t.length(); i++) {
                if(i + suf[mid] >= n) return 1;
                if(s[i + suf[mid]] > t[i]) return -1;
                else if(s[i + suf[mid]] < t[i]) return 1;
            }
            return 0;
        };

        int found1 = -1;
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int now = check(mid);
            if(now == 0) {
                found1 = mid;
                r = mid - 1;
            }
            else if(now == 1) l = mid + 1;
            else r = mid - 1;
        }

        int found2 = -2;
        l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int now = check(mid);
            if(now == 0) {
                found2 = mid;
                l = mid + 1;
            }
            else if(now == 1) l = mid + 1;
            else r = mid - 1;
        }
        cout << found2 - found1 + 1 << '\n';
    }
}
