//https://www.luogu.com.cn/problem/CF1336A
#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

int n, k;
vector<vector<int>>G;
vector<int>dep, siz, val;
bitset<200005>vis;

void dfs(int u, int fa) {
	siz[u] = 1;
	for (auto x : G[u]) {
		if (x == fa)	continue;
		dfs(x, u);
		siz[u] += siz[x];
	}
	val.push_back(dep[u]-siz[u]);
}

void sol() {
	cin >> n >> k;
	G.resize(n + 1);
	siz.assign(n + 1, 0);
	dep.assign(n + 1, 1e18+7);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int p = 1, ans = 0;
	queue<int>q;
	vis[1] = 1;
	dep[1] = 1;
	q.push(1);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : G[u]) {
			if (!vis[v]) {
				p++;
				q.push(v);
				dep[v] = dep[u] + 1;
				vis[v] = 1;
			}
		}
	}	
	
	dfs(1, 0);
	sort(all(val),greater<int>());
	for(int i=0;i<k;i++)	ans+=val[i];
	cout << ans;
}
//dep[u]-siz[u]+1
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
