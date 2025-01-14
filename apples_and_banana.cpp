#include <bits/stdc++.h>
using namespace std;
 
const double PI = acos(-1);
 
template<typename T>
vector<T> FFT(vector<T> a, int n, bool invert) {
    // https://codeforces.com/blog/entry/111371
    if(n == 1) return a;
    vector<T> even, odd;
    for(int i = 0; i < n; i += 2) even.push_back(a[i]);
    for(int i = 1; i < n; i += 2) odd.push_back(a[i]);
    even = FFT(even, n / 2, invert), odd = FFT(odd, n / 2, invert);
 
    double angle = 2 * PI / n * (invert ? -1 : 1);
    complex<double> wn(cos(angle), sin(angle)), curr(1);
 
    for(int i = 0; i < n / 2; i++) {
        a[i] = even[i] + curr * odd[i];
        a[i + n / 2] = even[i] - curr * odd[i];
        if(invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        curr *= wn;
    }
 
    return a;
}
 
int main(){
    int k, n, m; cin >> k >> n >> m;
    vector<int> a(k), b(k);
    for(int i = 0; i < n; i++) { 
        int x; cin >> x;
        --x;
        a[x] += 1;
    }
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        --x;
        b[x] += 1;
    }
 
    int len = 2 * k;
 
    while(len & (len - 1)) len += 1;
 
    vector<complex<double>> first(len), second(len);
 
    for(int i = 0; i < k; i++) first[i] = a[i];
    for(int i = 0; i < k; i++) second[i] = b[i];
 
    first = FFT(first, len, false), second = FFT(second, len, false);
 
    vector<complex<double>> ans(len);
    for(int i = 0; i < len; i++) {
        ans[i] = first[i] * second[i];
    }
 
    ans = FFT(ans, len, true);
 
    for(int i = 0; i < 2 * k - 1; i++) {
        long long now = round(ans[i].real());
        cout << now << ' ';
    }
    cout << '\n';
}
