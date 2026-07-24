#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

const int N = 50010;
int n, m;
vector<array<int, 12>> tr;
vector<int> cnt;
int tot;
vector<int> k;
vector<vector<int>> p;

void insert() {
	int u = 0;
	for (int i = 1; i <= m; i++) {
		int v = k[i];
		if (!tr[u][v]) {
			tr[u][v] = ++tot;
			if (tot >= (int)tr.size()) {
				tr.resize(tot + 1);
				cnt.resize(tot + 1);
			}
		}
		u = tr[u][v];
		cnt[u]++;
	}
}

int que(int o) {
	int u = 0;
	for (int i = 1; i <= m; i++) {
		int v = p[o][i];
		if (tr[u][v] && cnt[tr[u][v]]) {
			u = tr[u][v];
		} else {
			return i - 1;
		}
	}
	return m;
}

void sol() {
	cin >> n >> m;
	tot = 0;
	tr.assign(1, {}); // 根节点 0
	cnt.assign(1, 0);
	k.assign(m + 1, 0);
	p.assign(n + 1, vector<int>(m + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		vector<int> bucket(m + 1, 0); 
		for (int j = 1; j <= m; j++) {
			cin >> p[i][j];
			bucket[p[i][j]] = j;
		}
		for (int j = 1; j <= m; j++) {
			k[j] = bucket[j];
		}
		insert();
	}
	
	for (int i = 1; i <= n; i++) cout << que(i) << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		sol();
	}
	return 0;
}
//https://www.luogu.com.cn/problem/CF1792D
