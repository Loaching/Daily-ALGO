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
	for (int i = 1; i <= n; i++)	cin >> a[i];
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		int eq = 0;
		while (s.size() && a[s.top()] < a[i]) {
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
		while (s.size() && a[s.top()] > a[i]) {
			if (a[s.top()] == a[i]) eq = 1;
			ri2[s.top()] = i;
			s.pop();
		}
		if (s.size() && !eq) le2[i] = s.top();
		s.push(i);
	}
	
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		ans1 += a[i] * ((i - le1[i]) * (ri1[i] - i) - 1);
//		cout<<i<<' '<<a[i]<<' '<<((i - le1[i]) * (ri1[i] - i) - 1)<<"  hus  "<<((i - le2[i]) * (ri2[i] - i) - 1)<<'\n';
		ans2 += a[i] * ((i - le2[i]) * (ri2[i] - i) - 1);
	}
	cout << ans1 - ans2;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
/*
https://codeforces.com/contest/817/problem/D
*/
