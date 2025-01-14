#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

void FFT(vector<complex<double>> &a, int n, bool invert) {
    if(n == 1) return;

    // bit reversal
    for(int i = 0; i < n; i++) {
        int j = 0;
        for(int end = n / 2, start = 1; start < n; end /= 2, start *= 2) {
            if(start & i) j ^= end;
        }
        if(i < j) swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len *= 2) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        complex<double> wn(cos(angle), sin(angle));
        for(int i = 0; i < n; i += len) {
            complex<double> curr(1);
            for(int j = 0; j < len / 2; j++) {
                auto even = a[i + j], odd = curr * a[i + j + len / 2];
                a[i + j] = even + odd;
                a[i + j + len / 2] = even - odd;

                curr *= wn;
            }
        }
    }

    if(invert) for(auto &z : a) z /= n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // for each k
    //   sum(a[i] * b[j])
    //   i = j + k
    //   i - j = k
    //   i - (m - j - 1) = k
    //   i + j = k + m - 1
    int n, m; cin >> n >> m;
    int len = n + m + m - 1;
    while(len & (len - 1)) len += 1;
    vector<complex<double>> a(len), b(len);
    for(int i = m - 1; i < m - 1 + n; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b[m - i - 1] = x;
    }

    FFT(a, len, false);
    FFT(b, len, false);

    for(int i = 0; i < len; i++) a[i] *= b[i];

    FFT(a, len, true);

    for(int i = m - 1; i < m - 1 + m - 1 + n; i++) {
        long long now = round(a[i].real());
        cout << now << ' ';
    }

    cout << '\n';
}
