#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, val[100005], sze[100005],mxn=-INT_MAX;
vector<int> G[100005];
int dp[510232];

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> sze[i];
	for (int i = 1, u, v; i <= n - 1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void dfs(int u, int fa) {
	int siz=0;
	for (auto k : G[u]) {
		if (k == fa)	continue;
		dfs(k, u);
		siz+=(sze[k]>0)*sze[k];
	}
	sze[u]+=siz;
}

void sol() {
	dfs(1,0);
	int mxn=-INT_MAX;
	for(int i=1;i<=n;i++)	mxn=max(mxn,sze[i]);
	cout<<mxn;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	sol();

	return 0;
}
/*
https://www.luogu.com.cn/problem/P1122
*/
