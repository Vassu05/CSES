#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    multiset<int> st1, st2;
    vector<int> a(n);
    for(int i = 0; i < k - 1; i++) {
        int x; cin >> x;
        a[i] = x;
        st2.insert(x);
    }
    while(!st2.empty() && (int)st1.size() <= (int)st2.size()) {
        st1.insert(*st2.begin());
        st2.erase(st2.begin());
    }
    for(int i = k - 1; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
 
        if (st1.empty()) {
            st1.insert(x);
        }
        else if(x > *(--st1.end())) {
            st2.insert(x);
        }
        else {
            st2.insert(*(--st1.end()));
            st1.erase(--st1.end());
            st1.insert(x);
        }
 
        cout << *(--st1.end()) << ' ';
 
        if (st1.count(a[i - k + 1])) {
            st1.erase(st1.find(a[i - k + 1]));
            if(!st2.empty()) {
                st1.insert(*st2.begin());
                st2.erase(st2.begin());
            }
        }
        else {
            st2.erase(st2.find(a[i - k + 1]));
        }
    }
    cout << '\n';
}
