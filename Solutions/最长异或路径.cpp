#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 5000010;

vector<pair<int, int>>G[N];
int n, dis[N + 100], tr[N+1000][5], tot = 1, ans;

void insert(int x) {
	for (int i = 30, u = 1; i >= 0; i--) {
		int p = ((x >> i) & 1);
		if (!tr[u][p]) tr[u][p] = ++tot;
		u = tr[u][p];
	}
}

void get(int x) {
	int res = 0;
	for (int i = 30, u = 1; i >= 0; i--) {
		int p = ((x >> i) & 1);
		if (tr[u][p ^ 1]) {
			u = tr[u][p ^ 1];
			res ^= (1 << i);
		} else
			u = tr[u][p];
	}
	ans = max(ans, res);
}

void dfs(int u, int fa) {
	insert(dis[u]);
	
	for (auto x : G[u]) {
		int v = x.first, w = x.second;
		if (v == fa) continue;
		dis[v] = dis[u] ^ w;
		dfs(v, u);
	}
}

void sol() {
	cin >> n;
//	G.resize(n+5);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1, 0);
    get(dis[0]);
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
//https://www.luogu.com.cn/problem/P4551
