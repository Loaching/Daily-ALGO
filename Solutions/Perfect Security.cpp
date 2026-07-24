#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MXN = 30;
int tr[N * 31][2], cnt[N * 31], tot = 1;
int n;
vector<int> a;
void update(int val, int ooo) {
	int u = 1;
	for (int i = MXN; i >= 0; i--) {
		int v = (val >> i) & 1;
		if (!tr[u][v]) tr[u][v] = ++tot;
		u = tr[u][v];
		cnt[u] += ooo;
	}
}

int pos(int val) {
	int u = 1, res = 0;
	for (int i = MXN; i >= 0; i--) {
		int p = (val >> i) & 1;
		if (tr[u][p] && cnt[tr[u][p]] > 0) {
			u = tr[u][p];
		} else {
			res |= (1 << i);
			u = tr[u][p ^ 1];
		}
	}
	return res;
}

void sol() {
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		update(x, 1);
	}
	for (int i = 1; i <= n; i++) {
		int k = pos(a[i]);
		cout << k << ' ';
		int p_val = a[i] ^ k;
		update(p_val, -1);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sol();
	return 0;
}
//https://www.luogu.com.cn/problem/CF923C
