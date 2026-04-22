#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

int n;
vector<int> w(1005), dp(8, LONG_LONG_MAX), s(1005);

void sol() {
	cin >> n;
	string k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> k;
		int t = 0;
		for (char c : k) {
			if (c == 'A') t |= 1;
			if (c == 'B') t |= 2;
			if (c == 'C') t |= 4;
		}
		s[i] = t;
	}

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int m = 7; m >= 0; m--)
			if (dp[m] != LONG_LONG_MAX)
				dp[m | s[i]] = min(dp[m | s[i]], dp[m] + w[i]);

	if (dp[7] == LONG_LONG_MAX) cout << -1 << '\n';
	else cout << dp[7] << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	sol();
	return 0;
}
/*
https://www.luogu.com.cn/problem/CF1042B
*/
