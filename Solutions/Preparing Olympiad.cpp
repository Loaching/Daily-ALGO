#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

int n, l, r, x;
vector<int>a, dp((1 << 16), LONG_LONG_MAX);

void sol() {
	int ans = 0;
	cin >> n >> l >> r >> x;
	a.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0, mxn = 0, mnn = LONG_LONG_MAX;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				mxn = max(mxn, a[j]);
				mnn = min(mnn, a[j]);
				sum += a[j];
			}
		}
		if (mxn - mnn >= x && sum >= l && sum <= r) {
			ans++;
		}
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
https://www.luogu.com.cn/problem/CF550B
https://codeforces.com/problemset/problem/550/B
*/
