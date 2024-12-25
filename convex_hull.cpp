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
        return x == p.x ? y < p.y : x < p.x;
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
};


int main(){
    int n; cin >> n;
    vector<Point<long long>> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<Point<long long>> ans;
    
    for(int rep = 0; rep < 2; rep++) {
        int curr = ans.size();

        for(auto p : a) {
            while((int)ans.size() >= curr + 2) {
                Point<long long> x = ans.end()[-2];
                Point<long long> y = ans.end()[-1];
                if(y.cross(x, p) > 0) {
                    ans.pop_back();
                }
                else break;
            }
            ans.push_back(p);
        }

        ans.pop_back();
        reverse(a.begin(), a.end());
    }

    cout << ans.size() << '\n';

    for(auto i : ans) cout << i << '\n';
}
