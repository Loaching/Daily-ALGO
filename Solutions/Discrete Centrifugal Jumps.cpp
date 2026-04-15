#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a, dp, le1, ri1, le2, ri2;
int n;
void solve() {
	cin >> n;
	a.assign(n + 5, 0);
	dp.assign(n + 5, 2e18);
	le1.assign(n + 5, 0);
	ri1.assign(n + 5, n + 1);
	le2.assign(n + 5, 0);
	ri2.assign(n + 5, n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		int eq = 0;
		while (s.size() && a[s.top()] <= a[i]) {
			if (a[s.top()] == a[i]) eq = 1;
			ri1[s.top()] = i;
			s.pop();
		}
		if (s.size() && !eq) le1[i] = s.top();
		s.push(i);
	}
	while (s.size()) s.pop();
	for (int i = 1; i <= n; i++) {
		int eq = 0;
		while (s.size() && a[s.top()] >= a[i]) {
			if (a[s.top()] == a[i]) eq = 1;
			ri2[s.top()] = i;
			s.pop();
		}
		if (s.size() && !eq) le2[i] = s.top();
		s.push(i);
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1) dp[i] = min(dp[i], dp[i - 1] + 1);
		if (le1[i] >= 1) dp[i] = min(dp[i], dp[le1[i]] + 1);
		if (le2[i] >= 1) dp[i] = min(dp[i], dp[le2[i]] + 1);
		if (ri1[i] <= n) dp[ri1[i]] = min(dp[ri1[i]], dp[i] + 1);
		if (ri2[i] <= n) dp[ri2[i]] = min(dp[ri2[i]], dp[i] + 1);
	}
	cout << dp[n] << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	if (false) {
		cout << "LaLaLaLaLaLaLaLa,kulikulikulikuli";
	}
	while (T--) {
		solve();
	}
	return 0;
}
/*
https://codeforces.com/contest/1407/problem/D
*/
