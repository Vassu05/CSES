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
    int t; cin >> t;
    while(t--) [&]() {
        Point p1, p2, p3, p4; cin >> p1 >> p2 >> p3 >> p4;

        if((p1 - p2) * (p4 - p3) == 0) {

            // if p3 is not collinear w.r.t line segment p1 and p2
            if(p3.cross(p1, p2) != 0) {
                cout << "NO\n";
                return;
            }

            for(int rep = 0; rep < 2; rep++) {
                if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                    cout << "NO\n";
                    return;
                }
                swap(p1, p3);
                swap(p2, p4);
            }
            cout << "YES\n";
            return;
        }

        for(int rep = 0; rep < 2; rep++) {
            long long cross1 = (p2 - p1) * (p3 - p1);
            long long cross2 = (p2 - p1) * (p4 - p1);
            if((cross1 < 0 && cross2 < 0) || (cross1 > 0 && cross2 > 0)) {
                cout << "NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout << "YES\n";
    }();
}
