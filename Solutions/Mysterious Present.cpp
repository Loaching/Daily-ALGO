#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, w, h;
const int inf = 8416153418;

struct popo {
	int num, wde, hgh;
	bool operator<(const popo &x) const {
		if (wde == x.wde)	return  hgh > x.hgh;
		return wde < x.wde;
	}
};
vector<popo>a;

void init() {
	cin >> n >> w >> h;
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		if (x <= w || y <= h)	continue;
		a.emplace_back(popo{ i,x, y});
	}
	if (a.empty()) {
		cout << "0\n";
		return;
	}
	sort(a.begin(), a.end());
	
	vector<int>t, len(a.size());
	for (int i = 0; i < a.size(); i++) {
		int hi = a[i].hgh;
		auto it = lower_bound(t.begin(), t.end(), hi);
		if (it == t.end()) {
			t.push_back((hi));
			len[i] = t.size();
		} else {
			*it = hi;
			len[i] = it - t.begin() + 1;
		}
	}

	int k = t.size();
	cout << k << '\n';														//k为最长
	int curw = inf, curh = inf, cur = k;									
	vector<int>ans;

	for (int i = a.size() - 1; i >= 0; i--) {								//处理输出序列
		if (len[i] == cur && a[i].hgh < curh && a[i].wde < curw) {
			ans.push_back(a[i].num);
			cur--;
			curw = a[i].wde;
			curh = a[i].hgh;
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	for (auto x : ans)
		cout << x << ' ';

}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();

	return 0;
}
/*
https://codeforces.com/problemset/problem/4/D
学习此题重载运算符的写法，O(n log n)保留上升子序列的思想
*/
