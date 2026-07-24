#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], Time;
bool cut[MAXN];
int vis[MAXN], Group;
unsigned long long Num, Cut, ans1, ans2;
int n, m, Case;

void Init() {
	for (int i = 0; i <= n; ++i) G[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(cut, 0, sizeof(cut));
	memset(vis, 0, sizeof(vis));
	Time = n = Group = 0;
	ans1 = 0; ans2 = 1;
}

void Tarjan(int u, int fa) {
	dfn[u] = low[u] = ++Time;
	int child = 0;
	for (int v : G[u]) {
		if (v == fa) continue;
		if (!dfn[v]) {
			child++;
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (fa != 0 && low[v] >= dfn[u]) cut[u] = true;
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (fa == 0 && child >= 2) cut[u] = true;
}

void DFS(int u) {
	vis[u] = Group;
	Num++;
	for (int v : G[u]) {
		if (cut[v]) {
			if (vis[v] != Group) {
				Cut++;
				vis[v] = Group;
			}
		} else if (!vis[v]) {
			DFS(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Case = 1;
	while (cin >> m && m) {
		Init();
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			n = max(n, max(u, v));
		}
		for (int i = 1; i <= n; ++i)
			if (!dfn[i]) Tarjan(i, 0);
		
		for (int i = 1; i <= n; ++i) {
			if (!cut[i] && !vis[i]) {
				++Group;
				Num = Cut = 0;
				DFS(i);
				if (Cut == 0) {
					if (Num == 1) ans1 += 1;
					else {
						ans1 += 2;
						ans2 *= Num * (Num - 1) / 2;
					}
				} else if (Cut == 1) {
					ans1 += 1;
					ans2 *= Num;
				}
			}
		}
		cout << "Case " << Case++ << ": " << ans1 << " " << ans2 << "\n";
	}
	return 0;
}
//https://www.luogu.com.cn/problem/P3225
