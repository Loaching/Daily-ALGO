#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 500005;

int n, m;
vector<pair<int, int>> G[N];
int dfn[N], low[N], tim;
bool brg[N];
int fa[N];
vector<pair<int, int>> ans;

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) { x = get(x), y = get(y); if (x != y) fa[x] = y; }

void sol() {
	cin >> n >> m;
	vector<int> ua(m), va(m), du(m), dv(m);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		ua[i] = u, va[i] = v;
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}
	
	tim = 0;
	auto df = [&](auto&& self, int u, int pe) -> void {
		dfn[u] = low[u] = ++tim;
		for (auto [v, e] : G[u]) {
			if (e == pe) continue;
			if (!dfn[v]) {
				du[e] = u; dv[e] = v;
				self(self, v, e);
				low[u] = min(low[u], low[v]);
				if (low[v] > dfn[u]) brg[e] = true;
			} else if (dfn[v] < dfn[u]) {
				du[e] = u; dv[e] = v;
				low[u] = min(low[u], dfn[v]);
			}
		}
	};
	df(df, 1, -1);
	
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 0; i < m; ++i)
		if (!brg[i]) merge(ua[i], va[i]);
	
	vector<int> sz(n + 1, 0);
	for (int i = 1; i <= n; ++i) sz[get(i)]++;
	int mx = 1;
	for (int i = 1; i <= n; ++i)
		if (fa[i] == i && sz[i] > sz[mx]) mx = i;
	
	vector<vector<int>> tr(n + 1);
	map<pair<int,int>, int> mp;
	for (int i = 0; i < m; ++i) {
		if (brg[i]) {
			int fu = get(ua[i]), fv = get(va[i]);
			if (fu != fv) {
				tr[fu].push_back(fv);
				tr[fv].push_back(fu);
				mp[{fu, fv}] = mp[{fv, fu}] = i;
			}
		}
	}
	
	auto df2 = [&](auto&& self, int x, int p) -> void {
		for (int y : tr[x]) {
			if (y == p) continue;
			int eid = mp[{x, y}];
			int u = ua[eid], v = va[eid];
			if (get(u) == y && get(v) == x) du[eid] = u, dv[eid] = v;
			else du[eid] = v, dv[eid] = u;
			self(self, y, x);
		}
	};
	df2(df2, mx, 0);
	
	cout << sz[mx] << "\n";
	for (int i = 0; i < m; ++i)
		cout << du[i] << " " << dv[i] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) sol();
	return 0;
}
//https://www.luogu.com.cn/problem/CF732F
