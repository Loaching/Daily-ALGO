#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

int n, s;
vector<int> a;
vector<vector<int>> f;

void dfs1(int p, int c, int x) {
	if (p > n / 2) {
		f[c].push_back(x);
		return;
	}
	dfs1(p + 1, c + 1, x + a[p]);
	dfs1(p + 1, c, x);
}

int k, mn;

void dfs2(int p, int c, int x) {
	if (p > n) {
		int nd = k - c;
		if (nd < 0 || nd >= f.size())	return;
		auto &v = f[nd];
		if (v.empty())return;
		int t = s / 2 - x;
		auto it = lower_bound(all(v), t);
		if (it != v.end())		mn = min(mn, abs(s - 2 * (x + *it)));
		if (it != v.begin())	--it, mn = min(mn, abs(s - 2 * (x + *it)));
		return;
	}
	dfs2(p + 1, c + 1, x + a[p]);
	dfs2(p + 1, c, x);
}

void sol() {
	cin >> n;
	a.assign(n + 1, 0);
	s = 0;
	for (int i = 1; i <= n; i++)	cin >> a[i], s += a[i];
	k = n / 2;
	f.clear();
	f.resize(n / 2 + 1);
	mn = LONG_LONG_MAX;
	dfs1(1, 0, 0);
	for (auto &v : f)	sort(all(v));
	dfs2(n / 2 + 1, 0, 0);
	cout << mn << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		sol();
	}
	return 0;
}
//https://www.luogu.com.cn/problem/P3878
