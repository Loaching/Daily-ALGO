#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int>a;
vector<vector<int>>dp;

void init() {
	for (int j = 1; j <= __lg(n + 1); j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}

void ans(int st, int ed) {
	int len = __lg(ed - st + 1);
	cout << max(dp[st][len], dp[ed - (1 << len) +1][len]) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	a.resize(n + 1);
	dp.assign(n + 1, vector<int>(32, 0));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = a[i];

	}
	init();
	for (int i = 1, s, e; i <= m; i++) {
		cin >> s >> e;
		ans(s, e);
	}

	return 0;
}
