#include<bits/stdc++.h>
using namespace std;
const int mod = 10007;
#define int long long

int n;
vector<int> w;
vector<vector<int>> G;

void init() {
	cin >> n;
	w.resize(n + 1);
	G.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) cin >> w[i];
}

void sol() {
	int mxn = 0;
	int sum = 0;
	for (int u = 1; u <= n; u++) {
		if (G[u].size() < 2) continue;
		vector<int> nei;
		for (int v : G[u]) nei.push_back(w[v]);
		sort(nei.begin(), nei.end(), greater<int>());
		mxn = max(mxn, nei[0] * nei[1]);
		int s = 0, s2 = 0;
		for (int x : nei) {
			s = (s + x) % mod;
//			s2 = (s2 + x * x) % mod;
		}
//		sum = (sum + (s * s % mod - s2 + mod) % mod) % mod;
		for(auto x:nei){
			sum=(sum+x*(s-x)%mod)%mod;
		}
	}

	cout << mxn << " " << sum << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	sol();

	return 0;
}
/*
简单，枚举中间点
https://www.luogu.com.cn/problem/P1351
*/
