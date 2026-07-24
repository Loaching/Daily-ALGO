#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 6000010;

int tr[N][2], tot = 1, cnt[N];

void insert(int x, int v) {
	for (int i = 30, u = 1; i >= 0; i--) {
		int p = ((x >> i) & 1);
		if (!tr[u][p]) tr[u][p] = ++tot;
		u = tr[u][p];
		cnt[u] += v;
	}
}

int get(int x) {
	int res = 0;
	for (int i = 30, u = 1; i >= 0; i--) {
		int p = ((x >> i) & 1);
		if (tr[u][p ^ 1] && cnt[tr[u][p ^ 1]]) {
			u = tr[u][p ^ 1];
			res ^= (1 << i);
		} else
			u = tr[u][p];
	}
	return res;
}

void sol() {
	int q;
	cin >> q;
	insert(0, 1);
	while (q--) {
		char op;
		int x;
		cin >> op >> x;
		if (op == '+')	insert(x, 1);
		if (op == '-')	insert(x, -1);
		if (op == '?')	cout << get(x) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) {
		sol();
	}

	return 0;
}
//https://www.luogu.com.cn/problem/CF706D
