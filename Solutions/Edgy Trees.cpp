#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int mod = 1e9+7;

vector<int>fa, siz;

int qs(int x, int y) {
	if (y == 0)	return 1;
	int k = qs(x, y / 2) % mod;
	if (y % 2 == 0)	return k * k % mod;
	return x * k % mod * k % mod;
}

int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x, int y) {
	siz[get(x)] += siz[get(y)];
//	siz[get(y)] = 0;
	fa[get(y)] = get(x);
}

void sol() {
	int n, k;
	cin >> n >> k;
	fa.resize(n + 1);
	siz.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		siz[i] = 1;
	}
	for (int i = 1, u, v, typ; i < n; i++) {
		cin >> u >> v >> typ;
		if (!typ)	merge(u, v);
	}
	bitset<200005>vis;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[get(i)]) {
			ans = ans + qs( siz[get(i)], k);
			ans = ans % mod;
			vis[get(i)] = 1;
		}
	}
	ans = (qs(n, k) - ans + mod) % mod;
	cout << ans;


}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
//	cin>>T;
	while (T--) {
		sol();
	}

	return 0;
}
//https://www.luogu.com.cn/problem/CF1139C
