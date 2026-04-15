#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a, dp, le1, ri1, le2, ri2;
int n,mxn=0;
void solve() {
	cin >> n;
	a.assign(n + 5, 0);
	dp.assign(n + 5, 2e18);
	le1.assign(n + 5, 0);
	ri1.assign(n + 5, n + 1);
	le2.assign(n + 5, 0);
	ri2.assign(n + 5, n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stack<int> s;
	for(int i=1;i<=n;i++){
		while(s.size() && s.top()<a[i]){
			mxn=max(mxn,s.top()^a[i]);
			s.pop();
		}
		if(s.size()) mxn=max(mxn,a[i]^s.top());
		s.push(a[i]);
	}
	
	cout<<mxn;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	if (false) {
		cout << "LaLaLaLaLaLaLaLa,kulikulikulikuli";
	}
	while (T--) {
		solve();
	}
	return 0;
}
/*
https://codeforces.com/contest/280/problem/B
*/
