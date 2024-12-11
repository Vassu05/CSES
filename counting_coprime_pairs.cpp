#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    const int N = 1e6 + 10;
    vector<int> freq(N);

    vector<int> mobius(N, 1), prime(N, 1);
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            for(int j = i; j < N; j += i) { 
                mobius[j] *= -1;
                if(j > i) prime[j] = 0;
            }
            for(long long j = 1LL * i * i; j < N; j += 1LL * i * i) mobius[j] = 0; // because we only care about the number with prime powers = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x] += 1;
    }

    long long ans = 0;
    for(int i = 1; i < N; i++) {
        int c = 0;
        for(int j = i; j < N; j += i) c += freq[j];
        ans += 1LL * mobius[i] * c * (c - 1) / 2;
    }

    cout << ans << '\n';
}
