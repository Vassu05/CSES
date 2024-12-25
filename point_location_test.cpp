#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v){for (auto &it : v) cout << it << ' '; return ostream;}

template <typename T = int>
class Point {
    public:
    T x, y;

    Point<T>() {}

    Point<T>(T x, T y) {
        this.x = x;
        this.y = y;
    }

    Point<T>(const Point<T> &p) {
        x = p.x;
        y = p.y;
    }

    Point operator- (const Point &p) {
        return Point(this.x - p.x, this.y - p.y);
    }
    
    void operator -= (const Point &p) {
        x -= p.x, y -= p.y;
    }

    long long operator * (const Point &p) {
        return 1LL * x * p.y - 1LL * y * p.x;
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
    while(t--) {
        Point p1, p2, p3; 
        cin >> p1 >> p2 >> p3;
        p3 -= p1;
        p2 -= p1;
        long long cross_product = p2 * p3;
        if (cross_product < 0) cout << "RIGHT\n";
        else if (cross_product > 0) cout << "LEFT\n";
        else cout << "TOUCH\n";
    }
}
