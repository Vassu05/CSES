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

    long long area = 0; 
    for(int i = 0; i < n; i++) {
        area += a[i] * a[(i + 1) % n];
    }

    area = abs(area);

    long long boundary = 0;
    for(int i = 0; i < n; i++) {
        Point p = a[i] - a[(i + 1) % n];
        boundary += gcd(abs(p.x), abs(p.y));
    }

    // picks theorem
    // area = interior + boundary / 2 - 1;
    // interior = area - boundary / 2 + 1

    long long interior = (area - boundary) / 2 + 1; // here area is twice actually so divide it after substraction
    cout << interior << ' ' << boundary << '\n';
}
