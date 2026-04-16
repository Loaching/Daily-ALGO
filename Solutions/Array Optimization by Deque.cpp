#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int inf = 1e9+1;
vector<int>t;
int n;
int lowbit(int x) {
	return x & -x;
}

void add(int x, int v) {
	for (; x <= n; x += lowbit(x)) {
		t[x] += v;
	}
}

int query(int x) {
	int res = 0;
	for (; x > 0; x -= lowbit(x)) {
		res += t[x];
	}
	return res;
}

void sol() {
	cin >> n;
	deque<int>q;
	t.assign(n + 5, 0);
	vector<int>a, b;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		a.push_back(x);
		b.push_back(x);
	}

	sort(all(b));
	b.erase(unique(all(b)), b.end());
	for (int i = 0; i < n; i++)	a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

	int res = 0;
	for (auto x : a) {
		res += min(query(n) - query(x), query(x - 1));
		add(x, 1);
	}
	cout << res << '\n';
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
/*
https://codeforces.com/contest/1579/problem/E2
https://www.luogu.com.cn/problem/CF1579E2
*/
