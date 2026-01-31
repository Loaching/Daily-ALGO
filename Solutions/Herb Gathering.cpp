#include<bits/stdc++.h>
#define int long long
using namespace std;

int tme,mem;
int t[105],v[105];
vector<vector<int>>dp(1005,vector<int>(1005,0));

void init(){
	cin>>tme>>mem;
	for(int i=1;i<=mem;i++)	cin>>t[i]>>v[i];
}

void sol(){
	
	for(int i=1;i<=mem;i++){
		for(int j=tme;j>=1;j--){
			if(j>=t[i])	dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
			else		dp[i][j]=dp[i-1][j];
		}
	}	
	
	cout<<dp[mem][tme];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1048

第二次做这个题了，依旧错了两次才对，今后做类似背包问题时务必要判断背包空间是否足以装下以避免越界
*/
