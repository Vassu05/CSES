#include <bits/stdc++.h>
using namespace std;

#define int long long

class CHT {
    public:
    vector<int> a;
    vector<int> b;
    int front;
    CHT() : front(0) {}
    void add(int m, int c) {

        if(a.size() >= 1 && a.back() == m) {
            b.back() = min(b.back(), c);
            return;
        }

        while(a.size() >= 2) {
            int m1 = a.end()[-1], m2 = a.end()[-2];
            int c1 = b.end()[-1], c2 = b.end()[-2];

            // (c - c2) / (m2 - m) <= (c2 - c1) / (m1 - m2)
            if((c - c2) * (m2 - m1) < (c1 - c2) * (m2 - m)) {
                a.pop_back();
                b.pop_back();
            }
            else break;
        }
        a.push_back(m);
        b.push_back(c);
    }

    int query(int x) {
        while(front < a.size() - 1 && 1LL * a[front] * x + b[front] > 1LL * a[front + 1] * x + b[front + 1]) front += 1;
        return 1LL * a[front] * x + b[front];
        int l = 0, r = a.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            // x >= intersect(a[mid - 1], a[mid])
            // x >= (b[mid] - b[mid - 1]) / (a[mid - 1] - a[mid])
            // x * (a[mid - 1] - a[mid]) >= b[mid] - b[mid - 1]
            if(x * (a[mid - 1] - a[mid]) >= b[mid] - b[mid - 1]) {
                l = mid;
            }
            else r = mid - 1;
        }
        return a[l] * x + b[l];
    }
};

signed main(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    CHT hull;
    hull.add(k, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = hull.query(a[i]);
        hull.add(b[i], ans);
    }
    cout << ans;
}
