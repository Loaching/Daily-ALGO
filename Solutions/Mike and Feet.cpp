#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a, ile, iri, ans;
int n;

void init() {
	cin >> n;
	a.resize(n + 1);
	ile.resize(n + 1);
	iri.assign(n + 1, n + 1);
	ans.resize(n + 1);
	for (int i = 1; i <= n; i++)	cin >> a[i];
}

void sol() {
	stack<pair<int, int>>s;
	for (int i = 1; i <= n; i++) {    //right 1st min
		if (s.empty()) {
			s.push({a[i], i});
		} else {
			while (s.size() && a[i] <= s.top().first) {
				iri[s.top().second] = i;
				s.pop();
			}
			s.push({a[i], i});
		}
	}
	while (s.size()) {
		s.pop();
	}

	for (int i = 1; i <= n; i++) {
		if (s.empty()) {
			s.push({a[i], i});
		} else {
			while (s.size() && a[i] <= s.top().first) {
				s.pop();
			}
			if (s.size())	ile[i] = s.top().second;
			else			ile[i] = 0;
			s.push({a[i], i});
		}
	}

	for (int i = 1; i <= n; i++) {
		int len = iri[i] - ile[i] - 1;
		ans[len] = max(ans[len], a[i]);
//		cout << i << ' ' <<' ' << ile[i] << ' ' << iri[i] << '\n';
	}
	for (int i = n-1; i >= 1; i--) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= n; i++)	cout << ans[i] << ' ';
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
我脑子真不好用了
心好疼
*/
