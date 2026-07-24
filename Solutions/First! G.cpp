#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
		
const int N = 200005;
int nxt[N][126];
bool ed[N];
int tot = 0;
		
void insert(string s) {
	int u = 0;
	for (char c : s) {
		int idx = c;
		if (nxt[u][idx] == -1) {
			nxt[u][idx] = ++tot;
			memset(nxt[tot], -1, sizeof(nxt[tot]));
			ed[tot] = false;
		}
		u = nxt[u][idx];
	}
	ed[u] = true;
}
		
bool check(string s) {
	int u = 0;
	vector<int> G[126];
	int deg[126] = {0};
	bool vis[126][126] = {false};
	
	for (char v : s) {
		if (ed[u]) return false;
		for (int j = 97; j <='z'; ++j) {
			if (j != v && nxt[u][j] != -1) {
				if (!vis[v][j]) {
					G[v].push_back(j);
					deg[j]++;
					vis[v][j] = true;
				}
			}
		}
		u = nxt[u][v];
	}
	
	queue<int> q;
	for (int i = 'a'; i <= 'z'; i++)
		if (deg[i] == 0) q.push(i);
	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cnt++;
		for (int v : G[cur])
			if (--deg[v] == 0) q.push(v);
	}
	return cnt == 26;
}
		
void sol() {
	int n;
	cin >> n;
	memset(nxt[0], -1, sizeof(nxt[0]));
	ed[0] = false;
	tot = 0;
	
	vector<string> strs(n);
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
		insert(strs[i]);
	}
	
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		if (check(strs[i])) {
			ans.push_back(strs[i]);
		}
	}
	
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}
		
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	while (T--) sol();
	return 0;
}
//https://www.luogu.com.cn/problem/P3065
