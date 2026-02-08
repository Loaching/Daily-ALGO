#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000;
int n, b;
vector<int> a;

void init() {
	cin >> n >> b;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void sol() {
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == b) {
			pos = i;
			break;
		}
	}
	vector<int> cnt(N*2);
	int sum = 0;
	cnt[N] = 1;
	for (int i = pos - 1; i >= 1; i--) {
		if (a[i] > b) sum++;
		else sum--;
		cnt[sum + N]++;
	}
	sum = 0;
	int ans = cnt[N];
	for (int i = pos + 1; i <= n; i++) {
		if (a[i] > b) sum++;
		else sum--;
		ans += cnt[-sum + N];
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}

/*
放假了脑子就是不好用
弄简单一道题想半天
https://www.luogu.com.cn/problem/P1627
*/
