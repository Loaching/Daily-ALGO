#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>a;
vector<vector<int>>dp, dor;

int mxx(int st, int ed) {
	int len = __lg(ed - st + 1);
	return max(dp[st][len], dp[ed - (1 << len) +1][len]);
}

int orr(int st, int ed) {
	int len = __lg(ed - st + 1);
	return (dor[st][len] | dor[ed - (1 << len) +1][len]);
}

void init() {
	cin >> n;
	a.resize(n + 1);
	dp.assign(n + 1, vector<int>(32, 0));
	dor.assign(n + 1, vector<int>(32, 0));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = a[i];
		dor[i][0] = a[i];
	}

	for (int j = 1; j <= 20; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);

	for (int j = 1; j <= 20; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			dor[i][j] |= dor[i][j - 1] ;
			dor[i][j] |= dor[i + (1 << (j - 1))][j - 1];
		}

}

int sme(int k) {
	int lft = 1, rgt = k - 1;
	int le = k, ri = k;
	while (lft <= rgt) {
		int mid = (lft + rgt) >> 1;
		if (mxx(mid, k - 1) >= a[k]) {
			lft = mid + 1;
		} else {
			rgt = mid - 1;
			le = mid;
		}
	}

	lft = k + 1, rgt = n;
	while (lft <= rgt) {
		int mid = (lft + rgt) >> 1;
		if (mxx(k + 1, mid) > a[k]) {
			rgt = mid - 1;
		} else {
			lft = mid + 1;
			ri = mid;
		}
	}

	lft = le, rgt = k - 1;
	le=k;
	while (lft <= rgt) {
		int mid = (lft + rgt) >> 1;
		if (orr(mid, k) != a[k]) {
			lft = mid + 1;
		} else {
			rgt = mid - 1;
			le = mid;
		}
	}

	lft = k + 1, rgt = ri;
	ri=k;
	while (lft <= rgt) {
		int mid = (lft + rgt) >> 1;
		if (orr(k, mid) != a[k]) {
			rgt = mid - 1;
		} else {
			lft = mid + 1;
			ri = mid;
		}
	}
//	cout<<le<<" "<<ri<<"\n";
	return (k - le + 1) * (ri - k + 1);
}

void sol() {
	int as = (n * (n + 1)) / 2;
	for (int i = 1; i <= n; i++) {
//		cout << sme(i) << '\n';
		as -= sme(i);
	}
	cout << max(as, 0LL);
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
https://codeforces.com/problemset/problem/875/D
*/
