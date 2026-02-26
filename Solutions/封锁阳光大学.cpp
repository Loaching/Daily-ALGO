#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector<int> G[10005];
int col[10005];
int cnt1, cnt2;
bool flag=true;

void init() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

bool bfs(int st) {
	queue<int> q;
	q.push(st);
	col[st] = 1;
	cnt1 = 1; cnt2 = 0;
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			if (col[v] == 0) {
				col[v] = 3 - col[u];
				if (col[v] == 1) cnt1++;
				else cnt2++;
				q.push(v);
			} else if (col[v] == col[u]) {
				return false;
			}
		}
	}
	return true;
}

void sol() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0 && !G[i].empty()) {
			if (!bfs(i)) {
				cout << "Impossible" << '\n';
				return;
			}
			ans += min(cnt1, cnt2);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1330
染色，二分，孤立的点不管
*/
