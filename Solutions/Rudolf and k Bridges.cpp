#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e18;

void solve() {
	int n, m, k, d;
	cin >> n >> m >> k >> d;
	vector<int> a(m + 1), dp(m + 1, inf), ans(n + 1), b(n + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)	cin >> a[j];
		deque<int> q;
		dp.assign(m + 1, inf); 
		dp[1] = 1;
		q.clear();
		q.push_back(1);
		
		for (int j = 2; j <= m; j++) {
			while (!q.empty() && q.front() < j - d - 1)	q.pop_front();
			if (!q.empty())	dp[j] = dp[q.front()] + a[j] + 1;
			while (!q.empty() && dp[q.back()] >= dp[j]) 	q.pop_back();
			q.push_back(j);
		}
		ans[i] = dp[m];
	}
	int mnn = inf;
	for (int i = 1; i <= n; i++)	ans[i] += ans[i - 1]; 
	for (int i = k; i <= n; i++)	mnn = min(mnn, ans[i] - ans[i - k]);
	cout << mnn << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	if (false) {
		cout << "I wish you could see the wickyed truth.";
	}
	while (T--) {
		solve();
	}
	return 0;
}
/*
https://codeforces.com/contest/1941/problem/E
*/
