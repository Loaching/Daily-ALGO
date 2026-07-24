#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 6000010;

int tr[N][2], tot = 0, cnt[N];

void insert(int x) {
	for (int i = 30, u = 0; i >= 0; i--) {
		int p = ((x >> i) & 1);
		if (!tr[u][p]) tr[u][p] = ++tot;
		u = tr[u][p];
	}
}

int ans = LONG_LONG_MAX;
void dfs(int u, int val, int dep) {
	if (dep < 0) {
		ans = min(ans, val);
		return;
	}
	if		(tr[u][0] && !tr[u][1])	dfs(tr[u][0], val, dep - 1);
	else if	(tr[u][1] && !tr[u][0])	dfs(tr[u][1], val, dep - 1);
	else {
		dfs(tr[u][0], val^(1<<dep), dep - 1);
		dfs(tr[u][1], val^(1<<dep), dep - 1);
	}
}

void sol() {
	int n;
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		insert(x);
	}
	dfs(0, 0, 30);
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
//https://www.luogu.com.cn/problem/CF1285D
