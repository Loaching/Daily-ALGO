#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353;
vector<pair<int,int>>t;
vector<int>u,v,w;
vector<vector<int>>dp;
int n,m,T,k=0;

void init(){
	cin>>n>>m;
	t.resize(n);
	u.resize(m+1);
	v.resize(m+1);
	w.resize(m+1);
	dp.assign(n,vector<int>(n,inf));
	for(int i=0;i<n;i++){
		cin>>t[i].first;
		t[i].second=i;
		dp[i][i]=0;
	}
	sort(t.begin(),t.end());
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		dp[u[i]][v[i]]=dp[v[i]][u[i]]=w[i];
	}
}

void sol(){
	int a,b,num;
	cin>>a>>b>>num;
	while(k<n && t[k].first<=num){
		int mid=t[k].second;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid][j]);
		k++;
	}
	if(t[a].first>num || t[b].first>num || dp[a][b]==inf)
		cout<<"-1\n";
	else
		cout<<dp[a][b]<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>T;
	while(T--){
		sol();		
	}
	return 0;
}/*
https://www.luogu.com.cn/problem/P1119*/
