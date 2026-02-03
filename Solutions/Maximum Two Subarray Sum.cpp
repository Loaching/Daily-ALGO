#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>dp1(1e6+5);
vector<int>dp2(1e6+5);
int n;
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int mxn=LONG_LONG_MIN;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp1[i];
		dp2[i]=dp1[i];
	}
	for(int i=1;i<=n;i++)	dp1[i]=max(dp1[i],dp1[i-1]+dp1[i]);
	for(int i=n;i>=1;i--)	dp2[i]=max(dp2[i],dp2[i+1]+dp2[i]);
	
	for(int i=2;i<=n;i++)	dp1[i]=max(dp1[i],dp1[i-1]);
	for(int i=n-1;i>=1;i--)	dp2[i]=max(dp2[i],dp2[i+1]);
	
	for(int i=2;i<n;i++)	mxn=max(mxn,dp1[i-1]+dp2[i+1]);
	
	cout<<mxn;
	return 0;
}
/*
动态规划中一定注意边界！

应习得此题前后分别处理+最大值前缀和的优化思路以避免双重循环恐怖的时间复杂度

https://www.luogu.com.cn/problem/P2642
*/
