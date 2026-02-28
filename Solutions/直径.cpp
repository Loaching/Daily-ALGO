#include<bits/stdc++.h>
using namespace std;
#define int long long

int a, b;
int n, st, ans, sum;
vector<int> dis, pre, in, path, br;
vector<pair<int, int>> G[200008];


void dfs(int u, int fa, int p, int q) {
	pre[u] = fa;
	if (dis[u] > dis[st]) {
		st = u;
		ans = dis[u];
	}

	for (auto v : G[u]) {
		if (v.first == fa) continue;
		if ((u == p && v.first == q) || (u == q && v.first == p)) continue;
		dis[v.first] = dis[u] + v.second;
		dfs(v.first, u, p, q);
	}
}

int liangjianyong(int start, int p, int q) {
	dis.assign(n + 1, 0);
	dis[0] = -1;
	st = start;
	ans = 0;
	dfs(start, 0, p, q);
	a = st;
	dis.assign(n + 1, 0);
	dis[0] = -1;
	dfs(st, 0, p, q);
	b = st;
	return ans;
}

void init() {
	cin >> n;
	pre.resize(n + 1);
	in.resize(n + 1);
	br.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v, z;
		cin >> u >> v >> z;
		G[u].push_back({v, z});
		G[v].push_back({u, z});
	}
	cout << liangjianyong(1, 0, 0) << "\n";
}

void dfs2(int u, int fa) {
	for (auto x : G[u]) {
		int v = x.first, w = x.second;
		if (v == fa || in[v]) continue;
		dfs2(v, u);
		br[u] = max(br[u], br[v] + w);
	}
}

void sol() {
	int k = st;
	in.push_back(st);
	while (pre[k]) {
		path.push_back(pre[k]);
		in[pre[k]] = 1;
		k = pre[k];
	}
	reverse(path.begin(),path.end());
	for (auto v : path) {
		dfs2(v, 0);
	}
	int cnt = path.size();
	int l = 0, r = cnt - 1,len=ans;
//	cout<<len<<endl;
	for (int i = 0; i < cnt; i++)
		if (br[path[i]] == dis[path[i]])
			l = i;
	for (int i = cnt - 1; i >= 0; i--)
		if (br[path[i]] == len - dis[path[i]])
			r = i;
	int sum = max(r - l, 0LL);
	cout << sum << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	sol();

	return 0;
}
/*
天才，两端夹逼算出答案
https://www.luogu.com.cn/problem/P3304
*/
