#include <bits/stdc++.h>
using namespace std;


template <typename T = int>
class Point {
    public:
    T x, y;

    Point<T>() {}

    Point<T>(T x, T y) {
        this->x = x;
        this->y = y;
    }

    Point<T>(const Point<T> &p) {
        x = p.x;
        y = p.y;
    }

    Point operator- (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator+ (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    bool operator == (const Point &p) const {
        return x == p.x && y == p.y;
    }

    bool operator < (const Point &p) const {
        return y == p.y ? x < p.x : y < p.y;
    }
    
    void operator -= (const Point &p) {
        x -= p.x, y -= p.y;
    }

    void operator += (const Point &p) {
        x += p.x, y += p.y;
    }

    long long operator * (const Point &p) const {
        return 1LL * x * p.y - 1LL * y * p.x;
    }

    long long cross(const Point &p1, const Point &p2) {
        return (p1 - *this) * (p2 - *this);
    }

    friend istream &operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, Point &p) {
        os << p.x << ' ' << p.y;
        return os;
    }

    long long dist(const Point &p) const {
        return 1LL * (x - p.x) * (x - p.x) + 1LL * (y - p.y) * (y - p.y);
    }
};


int main(){
    int n; cin >> n;
    vector<Point<long long>> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end(), [&](auto x, auto y) {
        return x.x < y.x;
    });

    set<Point<long long>> st;
    int i = 0;
    long long ans = LLONG_MAX;
    for(auto p : a) {
        long long sq = sqrtl(ans) + 5;
        while(a[i].x < p.x - sq) {
            st.erase(a[i]);
            i += 1;
        }

        auto l = st.lower_bound(Point(p.x, p.y - sq));
        auto r = st.upper_bound(Point(p.x, p.y + sq));
        for(auto it = l; it != r; it++) {
            long long curr = p.dist(*it);
            if(curr < ans) ans = curr;
        }
        st.insert(p);
    }
    cout << ans << '\n';
}
