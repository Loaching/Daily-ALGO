#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>G;
vector<int>dp;					//dp[u]表示以u为终点的最大连续的蜈蚣图
int mxn = 1;

void dfs(int u, int fa) {
	int mx1 = -9, mx2 = -9;
	for (auto v : G[u]) {
		if (v == fa)	continue;
		dfs(v, u);
		int tmp = 0;
		if (G[v].size() > 3)	tmp = dp[v];
		if (G[v].size() == 3)	tmp = 1;
		if (tmp > mx1) {
			mx2 = mx1;
			mx1 = tmp;
		} else if (tmp > mx2) {
			mx2 = tmp;
		}
		if (G[u].size() >= 3)	dp[u] = max(dp[u], tmp + 1);
	}
	mxn = max((G[u].size() >= 4) * (mx1 + mx2 + 1), mxn);
	mxn = max(dp[u], mxn);
}


void sol() {
	mxn = 1;
	int n;
	cin >> n;
	dp.assign(n + 1, 0);
	G.assign(n + 1, vector<int>());
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << mxn << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Q;
	cin >> Q;
	while (Q--) {
		sol();
	}

	return 0;
}
/*
https://atcoder.jp/contests/abc447/tasks/abc447_f?lang=en

*/
