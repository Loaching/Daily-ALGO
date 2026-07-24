//https://www.luogu.com.cn/problem/CF193A
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20005;
int n, m;
vector<int> G[N];
int dfn[N], low[N], tim;
bool cut[N];
char a[100][100];

void dfs(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	int son = 0;
	for (int v : G[u]) {
		if (v == fa) continue;
		if (!dfn[v]) {
			son++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (fa != 0 && low[v] >= dfn[u]) cut[u] = true;
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (fa == 0 && son >= 2) cut[u] = true;
}

int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

int num(int x, int y) {
	return (x-1) * m + y;
}

void sol() {
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') cnt++;
		}
	}
	
	if (cnt <= 2) {
		cout << -1 << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != '#') continue;
			int u = num(i, j);
			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0], ny = j + dir[k][1];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (a[nx][ny] == '#') {
					int v = num(nx, ny);
					G[u].push_back(v);
				}
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (!dfn[i] && !G[i].empty()) {
			dfs(i, 0);
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (cut[i]) {
			cout << 1 << endl;
			return;
		}
	}
	
	cout << 2 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) sol();
	return 0;
}
