#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>dp1, dp2;

int mxx(int st, int ed) {
	int len = __lg(ed - st + 1);
	return max(dp1[st][len], dp1[ed - (1 << len) +1][len]);
}

int mnn(int st, int ed) {
	int len = __lg(ed - st + 1);
	return min(dp2[st][len], dp2[ed - (1 << len) +1][len]);
}

void sol() {
	int n;
	cin >> n;
	dp1.assign(n + 1, vector<int>(32, 0));
	dp2.assign(n + 1, vector<int>(32, 0));
	vector<int>a(n + 1), p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		dp1[i][0] = p[i];
		dp2[i][0] = p[i];
	}

	for (int j = 1; j <= __lg(n + 1); j++) {
		for (int i = 0; i + (1 << j) - 1 <= n; i++) {
			dp1[i][j] = max(dp1[i][j - 1], dp1[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int j = 1; j <= __lg(n + 1); j++) {
		for (int i = 0; i + (1 << j) - 1 <= n; i++) {
			dp2[i][j] = min(dp2[i][j - 1], dp2[i + (1 << (j - 1))][j - 1]);
		}
	}

	vector<int>fnt(n + 1), bck(n + 1, n + 1);
	stack<int>s;
	for (int i = 1; i <= n; i++) {
		while (s.size() && a[s.top()] < a[i]) {
			s.pop();
		}
		if (s.size())	fnt[i] = s.top();
		else			fnt[i] = 0;
		s.push(i);
	}

	while (s.size())	s.pop();

	for (int i = 1; i <= n; i++) {
		while (s.size() && a[i] > a[s.top()]) {
			bck[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (mxx(i, bck[i] - 1) - mnn(fnt[i], i - 1) > a[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	cin >> T;
	while (T--) {
		sol();
	}

	return 0;
}
/*
https://codeforces.com/contest/1691/problem/D
*/
