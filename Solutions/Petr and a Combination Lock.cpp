#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
#define cir 360
using namespace std;

int n;
vector<int>a,dp((1<<16),LONG_LONG_MAX);

void sol() {
	cin >> n;
	a.resize(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += a[j];
			} else {
				sum -= a[j];
			}
		}
		if (sum % 360 == 0)	{
			cout<<"YES\n";
			exit(0);
		}
	}
	cout<<"NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/CF1097B
https://codeforces.com/problemset/problem/1097/B
*/
