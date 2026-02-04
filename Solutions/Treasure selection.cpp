#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, tme;
vector<int> t, v;
vector<int> dp;

void init() {
	cin >> n >> tme;
	for (int i = 1; i <= n; i++) {
		int vi, wi, mi;
		cin >> vi >> wi >> mi;
		for (int k = 1; k <= mi; k *= 2) {
			v.push_back(vi * k);
			t.push_back(wi * k);
			mi -= k;
		}
		if (mi) {
			v.push_back(vi * mi);
			t.push_back(wi * mi);
		}
	}
	dp.resize(tme + 1, 0);
}

void sol() {
	for (int i = 0; i < (int)v.size(); i++)
		for (int j = tme; j >= t[i]; j--) 
			dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
	cout << dp[tme];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1776
还是AI哥教的好
我怎么就没想到可以用二进制拆分合并物品呢
*/
