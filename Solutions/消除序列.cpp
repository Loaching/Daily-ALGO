#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
vector<int>a, b, s, c, p;
vector<vector<int>>st;

int get(int l, int r) {
	if (l > r) return LLONG_MAX;
	int len = __lg(r - l + 1);
	return min(st[l][len], st[r - (1 << len) + 1][len]);
}

void init() {
	int ml = __lg(n + 1) + 1;
	for (int j = 1; j <= ml; j++) {
		for (int i = 0; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

void sol() {
	int m, ans = LONG_LONG_MAX;
	cin >> m;
	p.assign(m + 1, 0);
	vector<int> pre(m + 1, 0), bre(m + 2, 0);
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		pre[i] = pre[i - 1] + c[p[i]];
	}
	for (int i = m; i >= 1; i--) {
		bre[i] = bre[i + 1] + b[p[i]];
	}
	
	if (m >= 1) {
		int kl = p[1] - 1;
		if (kl >= 0) {
			int mb = get(0, kl);
			ans = min(ans, mb + (0 - bre[1]));
		}
	} else {
		ans = get(0, n);
	}
	
	for (int i = 1; i <= m; i++) {
		int l = p[i];
		int r = (i == m) ? n : p[i + 1] - 1;
		if (l > r) continue;
		int mb = get(l, r);
		ans = min(ans, mb + (pre[i] - bre[i + 1]));
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	a.resize(n + 1);
	b.resize(n + 1);
	c.resize(n + 1);
	s.resize(n + 1);
	int ml = __lg(n + 1) + 1;
	st.resize(n + 1, vector<int>(ml));
	
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++)	cin >> b[i], s[i] = b[i] + s[i - 1];
	for (int i = 1; i <= n; i++)	cin >> c[i];
	
	a[0] = 0;
	for (int k = 0; k <= n; k++) {
		st[k][0] = a[k] + (s[n] - s[k]);
	}
	init();
	
	cin >> q;
	for (int i = 1; i <= q; i++) {
		sol();
	}
	
	return 0;
}
/*

https://www.luogu.com.cn/problem/P9744

*/
