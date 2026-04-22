#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
int n;
vector<int> t, b, c, a, fnt, bck;
int lowbit(int x) {
	return x & -x;
}
void add(int k, int x, int v) {
	for (; x <= k; x += lowbit(x)) {
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
	a.resize(n + 5);
	c.resize(n + 5);
	t.resize(n + 5);
	fnt.resize(n + 5);
	bck.resize(n + 5);
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++)    b.push_back(a[i]);
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	int m = b.size();
	for (int i = 1; i <= n; i++)   c[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
	for (int i = 1; i <= n; i++) {
		add(m, c[i], 1);
		fnt[i] = query(c[i]) - query(c[i] - 1);
	}
	for (int i = 1; i <= n; i++)	t[i] = 0;
	
	for (int i = n; i >= 1; i--) {
		add(m, c[i], 1);
		bck[i] = query(c[i]) - query(c[i] - 1);
	}
	for (int i = 1; i <= n; i++)	t[i] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += i-1 - query(bck[i]);
		add(n, fnt[i], 1);
	}
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sol();
	return 0;
}
/*
https://www.luogu.com.cn/problem/CF459D
*/
