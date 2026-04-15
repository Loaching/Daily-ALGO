#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;
vector<vector<int>>st1, st2;
int n;

int mxx(int x, int y) {
	int len = __lg(y - x + 1);
	return max(st1[x][len], st1[y - (1 << len) +1][len]);
}

int mnn(int x, int y) {
	int len = __lg(y - x + 1);
	return min(st2[x][len], st2[y - (1 << len) +1][len]);
}

void solve() {
	cin >> n;
	a.assign(n + 5, 0);
	st1.assign(n + 5, vector<int>(30));
	st2.assign(n + 5, vector<int>(30));

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st1[i][0] = a[i];
		st2[i][0] = a[i];
	}

	for (int j = 1; j <= __lg(n + 1); j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
			st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int p = 1; p <= n - 2; p++) {
		int lft = -1, rgt = -1;
		int le = p + 2, ri = n;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			if (mxx(1, p) <= mxx(mid, n)) {
				if (mxx(1, p) == mxx(mid, n)) rgt = mid;
				le = mid + 1;
			} else {
				ri = mid - 1;
			}
		}
		le = p + 2, ri = n;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			if (mxx(1, p) < mxx(mid, n)) {
				le = mid + 1;
			} else {
				if (mxx(1, p) == mxx(mid, n)) lft = mid;
				ri = mid - 1;
			}
		}
//		cout << "Vocal " << lft << ' ' << rgt << '\n';
		if(lft==-1 or rgt==-1)	continue;
		le = lft - 1, ri = rgt - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			if (mnn(p + 1, mid) == mxx(mid + 1, n))	{
				cout << "YES\n";
				cout << p << ' ' << mid - p << ' ' << n - mid << '\n';
				return;
			}
			if (mnn(p + 1, mid) > mxx(mid + 1, n)) {
				le = mid + 1;
			} else {
				ri = mid - 1;
			}
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
/*
https://codeforces.com/contest/1454/problem/F
*/
