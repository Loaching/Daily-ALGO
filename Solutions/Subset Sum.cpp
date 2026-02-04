#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, tot;
bool flag = true;
vector<int> dp;

void init() {
	cin >> n;
	tot = n * (n + 1) / 2;
	if (tot & 1) {
		cout << "0";
		flag = false;
		return;
	}
	tot /= 2;
	dp.resize(tot + 1);
	dp[0] = 1;
}

void sol() {
	for (int i = 1; i <= n; i++) {
		for (int j = tot; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}
	cout << dp[tot] / 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	if (flag) sol();

	return 0;
}
/*
01背包变式....
我听说还有一种meet-in-middle的搜索方法，回头试试
https://www.luogu.com.cn/problem/P1466
*/
