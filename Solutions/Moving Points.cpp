#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
vector<int>t, q;
int n;
struct node {
	int p, v;
} a[10000005];
vector<int>b, c;

bool cmp(node x, node y) {
	if(x.v==y.v)	return x.p>y.p;
	return x.v > y.v;
}
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

void proadd(int x, int v) {
	for (; x <= n; x += lowbit(x)) {
		q[x] += v;
	}
}
int proquery(int x) {
	int res = 0;
	for (; x > 0; x -= lowbit(x)) {
		res += q[x];
	}
	return res;
}

void sol() {
	cin >> n;
	b.resize(n + 5);
	c.resize(n + 5);
	t.resize(n + 5);
	q.resize(n + 5);
	for (int i = 1; i <= n; i++) 	cin >> a[i].p;
	for (int i = 1; i <= n; i++)	cin >> a[i].v;

	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++)	b[i] = a[i].p;
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	for (int i = 1; i <= n; i++)	c[i] = lower_bound(all(b), a[i].p) - b.begin();
	for (int i = 1; i <= n; i++)	b[c[i]] = a[i].p;
	int k = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		k = query(n) - query(c[i]);
		ans += (proquery(n) - proquery(c[i])) - k * b[c[i]];
		add(c[i], 1);
		proadd(c[i], b[c[i]]);	
	}
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) {
		sol();
	}
	return 0;
}
/*
https://codeforces.com/problemset/problem/1311/F
https://www.luogu.com.cn/problem/CF1311F
*/
