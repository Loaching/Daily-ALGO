#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX;
vector<vector<pair<int,int>>> G;
vector<vector<int>>dis,vis;
int mxn=-inf,mnn=inf;
int n,m,k,st,ed;

void init(){
	cin>>n>>m>>k;
	G.resize(n);
	cin>>st>>ed;
	for(int i=1,u,v,z;i<=m;i++){
		cin>>u>>v>>z;
		G[u].emplace_back(v,z);
		G[v].emplace_back(u,z);
	}
}

void dijkstra(int st){
	priority_queue<pair<int,pair<int,int>>> q;
	dis.assign(n,vector<int>(k+1,inf));
	vis.assign(n,vector<int>(k+1,0));
	q.push({0,{st,0}});
	dis[st][0]=0;
	while(q.size()){
		int x=q.top().second.first,j=q.top().second.second;
		q.pop();
		if(vis[x][j])	continue;
		vis[x][j]=1;
		for(auto p : G[x]){
			int v=p.first,z=p.second;
			if(dis[v][j]>dis[x][j]+z){
				dis[v][j]=dis[x][j]+z;
				q.push({-dis[v][j],{v,j}});
			}
			if(dis[v][j+1]>dis[x][j] and j+1<=k){
				dis[v][j+1]=dis[x][j];
				q.push({-dis[v][j+1],{v,j+1}});
			}
		}
	}
}

void sol(){
	dijkstra(st);
	for(int i=0;i<=k;i++){
		mnn=min(dis[ed][i],mnn);
	}
	cout<<mnn;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P4568
使用分层图，可计算不同免费决策方式的最小花费
*/
