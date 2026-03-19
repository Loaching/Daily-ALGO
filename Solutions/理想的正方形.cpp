#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n, b, a, m;
//vector<vector<vector<int>>>dp1(1001, vector<vector<int>>(1001, vector<int>(7)));
//vector<vector<vector<int>>>dp2(1001, vector<vector<int>>(1001, vector<int>(7)));
int dp1[1001][1001][7],dp2[1001][1001][7];

int max4(int a1, int a2, int a3, int a4) {
	return max(max(a1, a2), max(a3, a4));
}

int min4(int a1, int a2, int a3, int a4) {
	return min(min(a1, a2), min(a3, a4));
}

int pls(int i, int j) {
	int len = __lg(n + 1);
	return max4(dp1[i][j][len], dp1[i][j + n - (1 << (len))][len], dp1[i + n -  (1 << (len))][j][len], dp1[i + n -  (1 << (len))][j + n -  (1 << (len))][len]);
}

int sub(int i, int j) {
	int len = __lg(n + 1);
	return min4(dp2[i][j][len], dp2[i][j + n - (1 << (len))][len], dp2[i + n -  (1 << (len))][j][len], dp2[i + n -  (1 << (len))][j + n -  (1 << (len))][len]);
}

void init() {
	for (int k = 1; k <= ceil(__lg(n + 1)); k++) {
		for (int i = 1; i + (1 << k) - 1 <= a; i++) {
			for (int j = 1; j + (1 << k) -1 <= b; j++) {
				dp1[i][j][k] = max4(dp1[i][j][k - 1], dp1[i][j + (1 << (k - 1))][k - 1], dp1[i + (1 << (k - 1))][j][k - 1], dp1[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]);
				dp2[i][j][k] = min4(dp2[i][j][k - 1], dp2[i][j + (1 << (k - 1))][k - 1], dp2[i + (1 << (k - 1))][j][k - 1], dp2[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]);
			}
		}
	}
}

void sol() {
	cin >> a >> b >> n;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> m;
			dp1[i][j][0] = m;
			dp2[i][j][0] = m;
		}
	}

	init();
	int mnn = INT_MAX;

	for (int i = 1; i + n - 1 <= a; i++)
		for (int j = 1; j + n - 1 <= b; j++)
			mnn = min(pls(i, j) - sub(i, j), mnn);

	cout << mnn;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sol();

	return 0;
}
/*
https://www.luogu.com.cn/problem/P2216
气笑了，静态数组占用内存比动态小
*/
