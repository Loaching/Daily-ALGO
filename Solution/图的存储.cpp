#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>G[1005];
int a[1005][1005],de[1005];
int main(){
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		a[u][v]=1;
		a[v][u]=1;
		de[u]++;
		de[v]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		cout<<de[i]<<' ';
		sort(G[i].begin(),G[i].end());
		for(int j=0;j<de[i];j++)	cout<<G[i][j]<<' ';
		cout<<'\n';
	} 
	return 0;
}
/*
弱智题...
https://www.luogu.com.cn/problem/B3643
*/
