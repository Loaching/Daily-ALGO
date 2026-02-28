#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 8;
int n;
vector<vector<pair<int, int>>> G;
vector<int> c;
vector<int> siz; 
vector<int> dis; 

void dfs1(int u, int fa) {
	siz[u] = c[u];
	for (auto x : G[u]) {
		int v = x.first, w = x.second;
		if (v == fa) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		dis[u] += dis[v] + siz[v] * w;
	}
}

void dfs2(int u, int fa) {
	for (auto &x : G[u]) {
		int v = x.first, w = x.second;
		if (v == fa) continue;
		dis[v] = dis[u] - siz[v] * w + (siz[1] - siz[v]) * w;
		dfs2(v, u);
	}
}

void solve() {
	cin >> n;
	
	G.assign(n + 1, vector<pair<int, int>>());
	c.assign(n + 1, 0);
	siz.assign(n + 1, 0);
	dis.assign(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	int minn = LONG_LONG_MAX;
	for (int i = 1; i <= n; i++) {
		minn = min(minn, dis[i]);
	}
	cout << minn << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
/*
另外一种做法是按照点权（忽视边权）使用DFS先找到重心接着用该重心结合边权算结果
我这个做法是先假设所有牛都去1点再挪动找答案
如图：https://cdn.luogu.com.cn/upload/image_hosting/ejqf9k20.png?x-oss-process=image/resize,m_lfit,h_170,w_225
https://www.luogu.com.cn/problem/P2986
*/
