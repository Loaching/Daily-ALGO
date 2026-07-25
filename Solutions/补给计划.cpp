#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

const int N = 205;
const int INF = 1e18;

int n, m, k;
int can[N];
int tgt[22];
int dis[N][N];

void floyd() {
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (dis[i][k] != INF && dis[k][j] != INF)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> can[i];
	for (int i = 0; i < k; ++i) cin >> tgt[i];
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dis[i][j] = INF;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
		dis[v][u] = min(dis[v][u], w);
	}
	
	floyd();
	
	vector<int> masks;
	for (int x = 1; x <= n; ++x) {
		if (!can[x]) continue;
		int mask = 0;
		for (int j = 0; j < k; ++j) {
			int city = tgt[j];
			if (dis[1][x] < INF && dis[x][city] < INF &&
				dis[1][x] + dis[x][city] == dis[1][city]) {
				mask |= (1 << j);
			}
		}
		if (mask > 0) masks.push_back(mask);
	}
	
	int full = (1 << k) - 1;
	vector<int> dp(1 << k, INF);
	dp[0] = 0;
	for (int mask : masks) {
		for (int state = full; state >= 0; --state) {
			if (dp[state] != INF) {
				int nxt = state | mask;
				dp[nxt] = min(dp[nxt], dp[state] + 1);
			}
		}
	}
	
	cout << dp[full] << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while (T--) sol();
	return 0;
}
//https://www.luogu.com.cn/problem/P10339
