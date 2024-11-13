#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k; cin >> n >> k;
    multiset<int> st1, st2;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long left = 0, right = 0;

    for(int i = 0; i < k - 1; i++) {
        st2.insert(a[i]);
        right += a[i];
    }
    while(!st2.empty() && (int)st1.size() <= (int)st2.size()) {

        right -= *st2.begin();
        left += *st2.begin();

        st1.insert(*st2.begin());
        st2.erase(st2.begin());
    }
    for(int i = k - 1; i < n; i++) {
        int x = a[i];
        if (st1.empty()) {
            st1.insert(x);
            left += x;
        }
        else if(x > *(--st1.end())) {
            st2.insert(x);
            right += x;
        }
        else {
            left -= *(--st1.end());
            right += *(--st1.end());
            left += x;
            st2.insert(*(--st1.end()));
            st1.erase(--st1.end());
            st1.insert(x);
        }

        int med = *(--st1.end());

        int l = (k + 1) / 2;

        long long req = 1LL * l * med - left + right - 1LL * (k - l) * med;

        cout << req << ' ';

        if (st1.count(a[i - k + 1])) {
            st1.erase(st1.find(a[i - k + 1]));
            left -= a[i - k + 1];
            if(!st2.empty()) {
                right -= *st2.begin();
                left += *st2.begin();
                st1.insert(*st2.begin());
                st2.erase(st2.begin());
            }
        }
        else {
            st2.erase(st2.find(a[i - k + 1]));
            right -= a[i - k + 1];
        }
    }
    cout << '\n';
}
