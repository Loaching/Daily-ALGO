#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = LONG_LONG_MAX;

void sol() {
	int n, x, y, mib = 1;

	cin >> n >> x >> y;
	vector<int>a(n + 1, 0), c(n - y + 1, 0), b(y - x + 1, 0);

	for (int i = 1; i <= x; i++) 	cin >> a[i];
	for (int i = 1; i <= y - x ; i++) {
		cin >> b[i];
		mib = b[i] < b[mib] ? i : mib;
	}
	for (int i = x + 1; i <= n + x - y; i++) 	cin >> a[i];

	int p = 1;
	while (a[p] <= b[mib] && p <= n + x - y) {
		cout << a[p] << ' ';
		p++;
	}

	for (int i = mib; i <= y - x; i++) 	cout << b[i] << ' ';
	for (int i = 1; i < mib; i++)			cout << b[i] << ' ';
	while (a[p] && p <= n + x - y) {
		cout << a[p] << ' ';
		p++;
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	cout << "wtfsmty\n";

	int T = 1;
	cin >> T;
	while (T--) sol();

	return 0;
}
/*
8 3 5
1 5 7 o 8 4 o 9 6 5

X+(8-5)


依旧弱智人做弱智题做半天
*/
