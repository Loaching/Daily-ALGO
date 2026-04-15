#include<bits/stdc++.h>
#define int long long
using namespace std;
int m, n, a, b;
vector<int>c, cnt;

int lowbit(int x) {
	return x & -x;
}

int query(int x) {
	int sum = 0;
	for (; x > 0; x -= lowbit(x)) {
		sum += c[x];
	}
	return sum;
}
void add(int x, int v) {
	for (; x <= n; x += lowbit(x)) {
		c[x] += v;
	}
}

void sol() {
	b=0;
	cin >> n;
	c.assign(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		b += query(n) - query(a - 1);
		add(a, 1);
	}
	cout << b << '\n';
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
https://codeforces.com/problemset/problem/1676/H2
*/
