#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s) {
    int n = s.length();
    vector<int> suf(n), pos(n);
    for(int i = 0; i < n; i++) {
        suf[i] = i;
        pos[i] = s[i];
    }
    for(int j = 1; j < n; j <<= 1) {
        // suf[i] -> store the index idx of subarray [idx...n - 1] where i is the sorted position of subarray s[idx:n-1]
        // pos[i] -> store the value of subarray [i...i + j - 1]
        auto comp = [&](int x, int y) -> bool {
            if(pos[x] != pos[y]) return pos[x] < pos[y];
            x += j, y += j;
            return (x < n && y < n) ? pos[x] < pos[y] : x > y;
        };
        sort(suf.begin(), suf.end(), comp);
        vector<int> temp(n);
        for(int i = 1; i < n; i++) {
            int now = 0;
            temp[i] = temp[i - 1] + (comp(suf[i - 1], suf[i]));
        }
        for(int i = 0; i < n; i++) {
            pos[suf[i]] = temp[i];
        }
    }
    return suf;
}

int main(){
    string s; cin >> s;
    auto suf = suffix_array(s);
    int q; cin >> q;
    int n = s.length();

    while (q--) {
        string t; cin >> t;
        int l = 0, r = n - 1;
        bool found = false;
        while(l <= r) {
            int mid = (l + r) / 2;
            int curr = 0, j = 0;
            for(;j < (int)t.length(); j++) {
                if(j + suf[mid] >= n) {
                    curr = -1;
                    break;
                }
                if(t[j] < s[j + suf[mid]]) {
                    curr = 1;
                    break;
                }
                if(t[j] > s[j + suf[mid]]) {
                    curr = -1;
                    break;
                }
            }
            if(j == (int)t.length()) {
                found = true;
                break;
            }
            else if(curr == -1) l = mid + 1;
            else r = mid - 1;
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}
