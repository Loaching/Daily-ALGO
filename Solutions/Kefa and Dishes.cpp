#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

int n, m, k, ans = 0, b[20][20];
int dp[(1 << 18) +1][18 + 1];
vector<int>a;

void sol() {
	cin >> n >> m >> k;

	a.resize(n + 1);
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0, x, y, c; i < k; i++) {
		cin >> x >> y >> c;
		b[x-1][y-1] = c;
	}

	for(int i=0;i<=n;i++)	dp[(1<<i)][i]=a[i];
	
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j)))	continue;
			for (int k = 0; k < n; k++) {
				if ((i & (1 << k)))	continue;
				dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + b[j][k] + a[k]);
			}
		}
	}
	
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i & (1<<j)) and __builtin_popcountll(i)==m){
				ans=max(ans,dp[i][j]);
			}
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
https://codeforces.com/problemset/problem/580/D
*/
