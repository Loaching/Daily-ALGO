#include<bits/stdc++.h>
#define int long long
using namespace std;

int tme,mem;
vector<int>t,v;
vector<int>dp;

void init(){
	cin>>tme>>mem;
	dp.resize(tme+1);
	t.resize(mem+1);
	v.resize(mem+1);
	for(int i=1;i<=mem;i++)	cin>>t[i]>>v[i];
}

void sol(){
	for(int i=1;i<=mem;i++){
		for(int j=1;j<=tme;j++){
			if(j>=t[i])	dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
		}
	}	
	cout<<dp[tme];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
和采药一样
完全背包版
*/
