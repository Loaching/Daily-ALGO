#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 500005;

int n, m;
vector<pair<int, int>> G[N];
int dfn[N], low[N], tim;
bool brg[N << 2];
int fa[N];
vector<pair<int, int>> ans;

int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x != y) fa[x] = y;
}

void dfs(int u, int fae) {
	dfn[u] = low[u] = ++tim;
	for (auto [v, id] : G[u]) {
		if (id == fae) continue;
		if (!dfn[v]) {
			dfs(v, id);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) {
				brg[id] = true;
				ans.push_back({u, v});
			}
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int u = 1; u <= n; u++) {
		for (auto [v, id] : G[u]) {
			if (!brg[id]) merge(u, v);
		}
	}
	vector<int> deg(n + 1, 0);
	for (auto [u, v] : ans) {
		int fu = get(u), fv = get(v);
		deg[fu]++;
		deg[fv]++;
	}
	
	int leaf = 0;
	for (int i = 1; i <= n; i++) {
		if (get(i) == i && deg[i] == 1) leaf++;
	}
	cout << (leaf + 1) / 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T = 1;
	while (T--){
		sol();
	}
	return 0;
}
//https://www.luogu.com.cn/problem/P2860
