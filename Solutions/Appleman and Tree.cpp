#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;
vector<int> G[N];
int color[N];
int dp[N][2];

void dfs(int u, int p) {
	if (color[u] == 1) {
		dp[u][1] = 1;
		dp[u][0] = 0;
	} else {
		dp[u][0] = 1;
		dp[u][1] = 0;
	}
	for (int v : G[u]) {
		if (v == p) continue;
		dfs(v, u);
		int old0 = dp[u][0], old1 = dp[u][1];
		dp[u][0] = old0 * (dp[v][0] + dp[v][1]) % MOD;
		dp[u][1] = (old1 * (dp[v][0] + dp[v][1]) + old0 * dp[v][1]) % MOD;
	}
}

void sol() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) G[i].clear();
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	for (int i = 0; i < n; ++i) cin >> color[i];
	dfs(0, -1);
	cout << dp[0][1] << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while (T--) sol();
	return 0;
}
//https://www.luogu.com.cn/problem/CF461B
