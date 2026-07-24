#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e6 + 10;
const int MXN = 30;
int tr[N * 31][2], tot = 1;
int cnt[N * 31];

void update(int val, int ooo) {
	int u = 1;
	for (int i = MXN; i >= 0; i--) {
		int v = (val >> i) & 1;
		if (!tr[u][v]) tr[u][v] = ++tot;
		u = tr[u][v];
		cnt[u] += ooo;
	}
}

int getless(int val) {
	int res = 0, u = 1;
	for (int i = MXN; i >= 0; i--) {
		if (!u) break;
		int v = (val >> i) & 1;
		if (v == 1) {
			res += cnt[tr[u][0]];
		}
		u = tr[u][v];
	}
	return res;
}

int getkth(int k) {
	int res = 0, u = 1;
	for (int i = MXN; i >= 0; i--) {
		if (!u) break;
		int le = cnt[tr[u][0]];
		if (le < k) {
			k -= le;
			u = tr[u][1];
			res += (1ll << i);
		} else {
			u = tr[u][0];
		}
	}
	return res;
}

int last = 0, ans = 0;
void sol() {
	int opt, x;
	cin >> opt >> x;
	x ^= last;
	if (opt == 1) {
		update(x, 1);
	} else if (opt == 2) {
		update(x, -1);
	} else if (opt == 3) {
		last = getless(x) + 1;
		ans ^= last;
	} else if (opt == 4) {
		last = getkth(x);
		ans ^= last;
	} else if (opt == 5) {
		last = getkth(getless(x));
		ans ^= last;
	} else if (opt == 6) {
		last = getkth(getless(x + 1) + 1);
		ans ^= last;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(x, 1);
	}
	
	while (m--) {
		sol();
	}
	
	cout << ans << '\n';
	return 0;
}
//https://www.luogu.com.cn/problem/P6136
