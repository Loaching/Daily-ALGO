#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 2e18;
int t, mxp, w;
vector<int>ap(2005), bp(2005), as(2005), bs(2005);
vector<vector<int>>dp;
void init() {
	cin >> t >> mxp >> w;
	for (int i = 1; i <= t; i++) {
		cin >> ap[i] >> bp[i] >> as[i] >> bs[i];
	}
	dp.assign(t + 5, vector<int>(mxp + 5, -inf));
}

void sol() {
//	deque<int>q;
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= as[i]; j++)	dp[i][j] = -j * ap[i];
		for (int j = 0; j <= mxp; j++)		dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		if (i <= w) continue;
		deque<int> q;
		for (int j = 0; j <= mxp; j++) {
			if (dp[i - w - 1][j] != -inf) {
				while (q.size() && dp[i - w - 1][q.back()] + q.back() * ap[i] <= dp[i - w - 1][j] + j * ap[i])	q.pop_back();
				q.push_back(j);
			}
			while (q.size() && q.front() < j - as[i]) q.pop_front();
			if (q.size()) {
				dp[i][j] = max(dp[i][j], dp[i - w - 1][q.front()] + q.front() * ap[i] - j * ap[i]);
			}
		}
		q.clear();
		for (int j = mxp; j >= 0; j--) {
			if (dp[i - w - 1][j] != -inf) {
				while (q.size() && dp[i - w - 1][q.back()] + q.back() * bp[i] <= dp[i - w - 1][j] + j * bp[i])	q.pop_back();
				q.push_back(j);
			}
			while (q.size() && q.front() > j + bs[i]) q.pop_front();
			if (q.size()) {
				dp[i][j] = max(dp[i][j], dp[i - w - 1][q.front()] + q.front() * bp[i] - j * bp[i]);
			}
		}
	}
	cout << dp[t][0];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	if (false) {
		cout << "Take a leap in to the blazzing";
	}
	while (T--) {
		init();
		sol();
	}
	return 0;
}
/*
https://www.luogu.com.cn/problem/P2569
*/
