#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a, ini;
int n;

void sol() {
	stack<pair<int, int>>s;
	for (int i = 1; i <= n; i++) {
		if (s.empty()) {
			s.push({a[i], i});
		} else {
			while (s.size() && a[i] > s.top().first) {
				ini[s.top().second] = i;
				s.pop();
			}
			s.push({a[i], i});
		}
	}
	for (int i = 1; i <= n; i++)	if (!ini[i])	ini[i] = 0;
}

signed main() {

	cin >> n;
	a.resize(n + 1);
	ini.resize(n + 1);
	for (int i = 1; i <= n; i++)	cin >> a[i];
	sol();
	for (int i = 1; i <= n; i++)	cout << ini[i] << ' ';
}
/*
https://www.luogu.com.cn/problem/P5788
模板
*/
