#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int vis[N][N];
int cnt;

bool isValid(int x, int y) { return x >= 0 && y >= 0 && x < N && y < N; }

int give(int x, int y) {
	int count = 0;
	for(int i = -2; i <= 2; i++) for(int j = -2; j <= 2; j++) {
		if(abs(i) + abs(j) == 3) {
			int nx = x + i, ny = y + j;
			if(isValid(nx, ny) && !vis[nx][ny]) count += 1;
		}
	}
	return count;
}

bool dfs(int x, int y) {
	if(vis[x][y]) return false;
	vis[x][y] = cnt;
	cnt += 1;
	if(cnt == N * N + 1) return true;
	vector<tuple<int,int,int>> collect;
	for(int i = -2; i <= 2; i++) for(int j = -2; j <= 2; j++) if(abs(i) + abs(j) == 3) {
		int nx = x + i, ny = y + j;
		if(isValid(nx, ny) && !vis[nx][ny]) collect.emplace_back(nx, ny, give(nx, ny));
	}
	sort(collect.begin(), collect.end(), [&](tuple<int,int,int> p, tuple<int,int,int> q) {
		return get<2>(p) < get<2>(q);
	});
	for(auto [p, q, r] : collect) {
		if(dfs(p, q)) return true;
	}
	vis[x][y] = 0;
	cnt -= 1;
	return false;
}

int main() {
	int x, y; cin >> y >> x;
	--x, --y;
	cnt = 1;
	dfs(x, y);
	for(int i = 0; i < N; i++) { 
		for(int j = 0; j < N; j++) {
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
}