#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = LONG_LONG_MAX;
vector<vector<pair<int, int>>> G;
vector<int>dis, vis;
int mxn = -inf, mnn = inf;
int n, m;

void init() {
	cin >> n >> m;
	G.resize(3 * n + 1);
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		G[i].push_back({i + n, -x});
		G[i + n].push_back({i + 2 * n, x});
	}
	for (int i = 1; i <= m; i++) {
		int u, v, z;
		cin >> u >> v >> z;
		G[u].push_back({v, 0});
		G[u + n].push_back({v + n, 0});
		G[u + 2 * n].push_back({v + 2 * n, 0});
		if (z == 2) {
			G[v].push_back({u, 0});
			G[v + n].push_back({u + n, 0});
			G[v + 2 * n].push_back({u + 2 * n, 0});
		}
	}

}

void spfa() {
	queue<int>q;
	q.push(1);
	dis.assign(n * 3 + 1, -inf);
	vis.assign(n * 3 + 1, 0);
	dis[1] = 0;
	vis[1] = 1;
	while (q.size()) {
		int x = q.front();
		vis[x] = 0;
		q.pop();
		for (auto p : G[x]) {
			int y = p.first, z = p.second;
			if (dis[y] < dis[x] + z) {
				dis[y] = dis[x] + z;
				if (!vis[y]) {
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

void sol() {
	spfa();
	int ans = max(0LL, dis[3 * n]);
	cout << ans;
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
https://www.luogu.com.cn/problem/P1073
因为仅有一次售卖所以可手动将dis/vis数组划分为1~n,n+1~2n,2n+1~3n分别表示未购买时，持有时，售卖后
因其仅在购买时（也就是层与层之间的连接）有边权所以使用spfa将不会爆
因为在第1，3两层绝不可能走回头路，复杂度O(n)级别？
*/
