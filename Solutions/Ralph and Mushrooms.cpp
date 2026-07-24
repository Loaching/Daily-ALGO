#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 1e6 + 5;
int n, m, s;
vector<pair<int, int>> G[N];
int u[N], v[N], w[N];
int dfn[N], low[N], ins[N], bel[N];
stack<int> stk;
int tim, scn;
int val[N];
vector<pair<int, int>> H[N];
int deg[N];
bool vis[N];
int dp[N];
int cur(int wg) {
	if (wg == 0) return 0;
	int K = (1 + sqrt(1 + 8.0 * wg)) / 2;
	while (K * (K - 1) / 2 <= wg) K++;
	while (K * (K - 1) / 2 > wg) K--;
	return K * wg - (K - 1) * K * (K + 1) / 6;
}
void dfs(int curr) {
	dfn[curr] = low[curr] = ++tim;
	stk.push(curr);
	ins[curr] = 1;
	for (auto edge : G[curr]) {
		int nex = edge.first;
		if (!dfn[nex]) {
			dfs(nex);
			low[curr] = min(low[curr], low[nex]);
		} else if (ins[nex]) {
			low[curr] = min(low[curr], dfn[nex]);
		}
	}
	if (low[curr] == dfn[curr]) {
		scn++;
		int topv;
		do {
			topv = stk.top();
			stk.pop();
			bel[topv] = scn;
			ins[topv] = 0;
		} while (topv != curr);
	}
}
void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		G[u[i]].push_back({v[i], w[i]});
	}
	cin >> s;
	tim = scn = 0;
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) dfs(i);
	for (int i = 1; i <= m; i++) {
		int x = u[i], y = v[i], wgt = w[i];
		if (bel[x] == bel[y]) {
			val[bel[x]] += cur(wgt);
		} else {
			H[bel[x]].push_back({bel[y], wgt});
			deg[bel[y]]++;
		}
	}
	int st = bel[s];
	for (int i = 1; i <= scn; i++) dp[i] = -1;
	dp[st] = val[st];
	queue<int> q;
	for (int i = 1; i <= scn; i++) {
		if (deg[i] == 0) q.push(i);
	}
	int ans = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (dp[curr] != -1) ans = max(ans, dp[curr]);
		for (auto edge : H[curr]) {
			int nex = edge.first;
			int weight = edge.second;
			if (dp[curr] != -1) {
				dp[nex] = max(dp[nex], dp[curr] + weight + val[nex]);
			}
			deg[nex]--;
			if (deg[nex] == 0) q.push(nex);
		}
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) sol();
	return 0;
}
//https://www.luogu.com.cn/problem/CF894E
