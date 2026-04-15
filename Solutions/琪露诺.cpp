#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a, dp, ini;
int n, l, r;
void solve() {
	cin >> n >> l >> r;
	bitset<200005>vis(0);
	dp.assign(n + r + 1, -2e18);
	a.resize(n + r + 1);
	ini.resize(n + r + 1);
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	deque<int>q;
	dp[0] = 0;
	for (int i = l; i <= n; i++) {
		while (q.size() && dp[i - l] > dp[q.back()])	q.pop_back();
		q.push_back(i - l);
		if (q.size() && q.front() < i - r)		q.pop_front();
		if (dp[q.front()] != -2e18)	dp[i] = max(dp[i], a[i] + dp[q.front()]);
	}
	int mxn = -2e18;
	for (int i = n - r + 1; i <= n; i++) {
		mxn = max(mxn, dp[i]);
	}
	cout << mxn;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	if (false) {
		cout << "Hush,Don't speak";
	}
	while (T--) {
		solve();
	}
	return 0;
}
/*
我在忠山很像梁见永
https://www.luogu.com.cn/problem/P1725
*/
