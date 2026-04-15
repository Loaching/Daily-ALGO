#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>a, fnt, bck;

void show(int st) {
	vector<int>ans;
	ans.resize(n + 1);
	ans[st] = a[st];
	for (int i = st - 1; i >= 1; i--) {
		ans[i] = min(a[i], ans[i + 1]);
	}
	for (int i = st + 1; i <= n; i++) {
		ans[i] = min(a[i], ans[i - 1]);
	}

	for (int i = 1; i <= n; i++)	cout << ans[i] << ' ';
}

void sol() {
	cin >> n;
	a.resize(n + 5);
	fnt.resize(n + 5);
	bck.resize(n + 5);
	stack<int>s;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		while (s.size() && a[s.top()] > a[i]) {
			s.pop();
		}
		if (s.size())	fnt[i] = (i - s.top()) * a[i] + fnt[s.top()];
		else			fnt[i] = (i) * a[i];
		s.push(i);
	}

	while (s.size())	s.pop();

	for (int i = n; i >= 1; i--) {
		while (s.size() && a[s.top()] > a[i]) {
			s.pop();
		}
		if (s.size()) 	bck[i] = (s.top() - i) * a[i] + bck[s.top()];
		else			bck[i] = (n-i+1) * a[i];
		s.push(i);
	}
//
//	for(int i=1;i<=n;i++)	cout<<fnt[i]<<' ';
//	cout<<'\n';
//	for(int i=1;i<=n;i++)	cout<<bck[i]<<' ';
//
	int mxn = 0;
	for (int i = 1; i <= n; i++) {
		bck[i] = bck[i] + fnt[i] -a[i];
		if (bck[i] > bck[mxn])	mxn = i;
	}
//	cout << "\n" << mxn << "\n";
	show(mxn);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sol();

	return 0;
}
/*
https://codeforces.com/contest/1313/problem/C2
*/
