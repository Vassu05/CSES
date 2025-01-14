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
    // 1001011010
    // for each k
    // sum(s[i] * s[j])
    // i - j = k
    // i - (n - j + 1) = k
    // i + j - (n - 1) = k
    // i + j = k + n - 1

    string s; cin >> s;
    int n = s.length();
    int len = 2 * n;
    while(len & (len - 1)) len += 1;
    vector<complex<double>> a(len), b(len);
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        b[n - i - 1] = s[i] - '0';
    }

    a = FFT(a, len, false);
    b = FFT(b, len, false);

    vector<complex<double>> ans(len);
    for(int i = 0; i < len; i++) ans[i] = a[i] * b[i];
    ans = FFT(ans, len, true);

    for(int i = n - 1 + 1; i <= n - 1 + n - 1; i++) {
        long long now = round(ans[i].real());
        cout << now << ' ';
    }

    cout << '\n';

}
