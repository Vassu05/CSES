#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;
class Line {
    public:
    // #define int long long (check whether you need this)
    // #define double long double
    int m, c, query;
    double intersection;
    bool flag;
    // m -> slope, c -> y-intercept, p->point of intersection with next line in the hull
    Line () {}
    Line(int a, int b) : m(a), c(b), intersection(-inf), query(0), flag(false) {}
    int calc(int x) const { return m * x + c; }
    bool parallel(const Line &l) const { return m == l.m; }
    double intersect(const Line &l) const {
        return parallel(l) ? -inf : 1.0 * (l.c - c)  / (m - l.m);
    }
    bool operator<(const Line &l) const {
        if(l.flag) return intersection < l.query;
        else return m > l.m;
    }
};

class CHT {
    public:
    multiset<Line> hull;
    typedef multiset<Line>::iterator iter;

    CHT() {}

    bool cPrev(iter it) { return it != hull.begin(); }
    bool cNext(iter it) { return it != hull.end() && next(it) != hull.end(); }
    bool bad(const Line &prev, const Line &curr, const Line &next) {
        return prev.intersect(next) <= prev.intersect(curr);
    }
    bool bad(iter it) {
        return cPrev(it) && cNext(it) && bad(*prev(it), *it, *next(it));
    }

    iter update(iter it) {
        if(!cPrev(it)) return it;
        auto intersectsAt = it->intersect(*prev(it));
        Line tmp(*it);
        tmp.intersection = intersectsAt;
        hull.erase(it);
        return hull.insert(tmp);
    }

    void add(int m, int c) {
        Line now(m, c);

        auto it = hull.lower_bound(now);
        while(it != hull.end() && now.parallel(*it)) {
            if(it->c > c) it = hull.erase(it);
            else return;
        }

        auto curr = hull.insert(now);

        if(bad(curr)) { 
            hull.erase(curr);
            return;
        }

        while(cNext(curr) && bad(next(curr))) hull.erase(next(curr));
        while(cPrev(curr) && bad(prev(curr))) hull.erase(prev(curr)); 
        curr = update(curr);
        if(cPrev(curr)) update(prev(curr));
        if(cNext(curr)) update(next(curr));
    }
    int query(int x) {
        Line now;
        now.query = x, now.flag = true;
        auto it = hull.lower_bound(now);
        it--;
        return it->calc(x);
    }
};

int32_t main(){
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    CHT hull;
    hull.add(x, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = hull.query(a[i]);
        if(ans == 0) {
            cout << i << ' ';
        }
        hull.add(b[i], ans);
    }

    cout << ans << '\n';
}
