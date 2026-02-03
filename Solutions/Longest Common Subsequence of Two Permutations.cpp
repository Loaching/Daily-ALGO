#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int>d,f;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int>a(n+n), b(n+n);
	f.resize(n+n);
	for (int i = 1; i <= n; i++)	cin >> a[i],f[a[i]]=i;
	for (int i = 1; i <= n; i++)	cin >> b[i],b[i]=f[b[i]];
	
	for(int i=1;i<=n;i++){
		if(i==1 or b[i]>d.back())	d.push_back(b[i]);
		else	*lower_bound(d.begin(),d.end(),b[i])=b[i];
	}
	
	cout<<d.size();
	return 0;
}
/*
5
3 2 1 4 5
1 2 3 4 5
对于排列的最长子序列可以通过对某个排列建立由1~n的映射从而将题目转化为最长上升子序列问题
https://www.luogu.com.cn/problem/P1439
*/
