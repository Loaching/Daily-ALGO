#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
int tr[500005][10], cnt[500005], ed[500005];

int tot = 0;
void iet(string s) {
	int p = 0;
	for (auto ch : s) {
		int v = ch - 48;
		if (!tr[p][v])	tr[p][v] = ++tot;
		p = tr[p][v];
		cnt[p]++;
	}
	ed[p]++;
}

int fnd(string s) {
	int p = 0, sm = 0;
	for (auto ch : s) {
		int v = ch - 48;
		if (!tr[p][v])	return sm + ed[p];
		sm += ed[p];
		p = tr[p][v];
	}
	return cnt[p] + sm;
}

void sol() {
	int n, m;
	cin >> m >> n;

	for (int i = 1, b; i <= m; i++) {
		string s;
		cin >> b;
		while (b--) {
			char x;
			cin >> x;
			s += x;
		}
		iet(s);
	}
	for (int i = 1, b; i <= n; i++) {
		string s;
		cin >> b;
		while (b--) {
			char x;
			cin >> x;
			s += x;
		}
		cout << fnd(s) << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
//	freopen("P2922_2.in","r",stdin);
//	freopen("edjsi.txt","w",stdout);

	int T = 1;
//	cin>>T;
	while (T--) {
		sol();
	}

	return 0;
}
/*

https://www.luogu.com.cn/problem/P2922

*/
