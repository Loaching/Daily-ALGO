#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>dp(1e6);
int n;
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int mxn=-99999;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i];
		dp[i]=max(dp[i]+dp[i-1],dp[i]);
		mxn=max(mxn,dp[i]);
	}
	cout<<mxn;
	return 0;
}
/*
7
2 -4 3 -1 2 -4 3
*/
//https://www.luogu.com.cn/problem/P1115
//简简单单，无需多言
