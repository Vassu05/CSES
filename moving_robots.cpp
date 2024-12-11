#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 8;
    int k; cin >> k;
    vector<vector< vector<vector<double>> >> ans(n, vector<vector< vector<double> >> (n, vector<vector<double>> (n, vector<double> (n))));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans[i][j][i][j] = 1;

    auto process = [&]( vector<vector<double>> dp) -> vector<vector<double>>  {
        vector<vector<double>> ans(n, vector<double> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                for(int x = -1; x <= 1; x++) for(int y = -1; y <= 1; y++) if(abs(x) != abs(y)) {
                    int nx = x + i, ny = y + j;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    count += 1;
                }
                for(int x = -1; x <= 1; x++) for(int y = -1; y <= 1; y++) if(abs(x) != abs(y)) {
                    int nx = x + i, ny = y + j;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    ans[nx][ny] += dp[i][j] / count;
                }
            }
        }
        return ans;
    };

    auto move = [&]() -> void {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = process(ans[i][j]);
            }
        }
    };

    for(int i = 0; i < k; i++) move();


    auto get = [&](int x, int y) -> double {
        double res = 1;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            res *= (1 - ans[i][j][x][y]);
        }
        return res;
    };

    double res = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) res += get(i, j);

    cout << fixed << setprecision(6) << res << '\n';
}
