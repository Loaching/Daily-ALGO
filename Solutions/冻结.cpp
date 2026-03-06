#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX;
vector<vector<pair<int,int>>> G;
vector<vector<int>>dis,vis;
int n,m,k;

void init(){
	cin>>n>>m>>k;
	G.resize(n+1);
	for(int i=1,u,v,z;i<=m;i++){
		cin>>u>>v>>z;
		G[u].emplace_back(v,z);
		G[v].emplace_back(u,z);
	}
}

void dijkstra(){
	int st=1;
	priority_queue<pair<int,pair<int,int>>> q;
	dis.assign(n+1,vector<int>(k+1,inf));
	vis.assign(n+1,vector<int>(k+1,0));
	q.push({0,{st,0}});
	dis[st][0]=0;
	while(q.size()){
		int x=q.top().second.first,j=q.top().second.second;
		q.pop();
		if(vis[x][j]) continue;
		vis[x][j]=1;
		for(auto p : G[x]){
			int v=p.first,z=p.second;
			if(dis[v][j]>dis[x][j]+z){
				dis[v][j]=dis[x][j]+z;
				q.push({-dis[v][j],{v,j}});
			}
			if(j+1<=k && dis[v][j+1]>dis[x][j]+z/2){
				dis[v][j+1]=dis[x][j]+z/2;
				q.push({-dis[v][j+1],{v,j+1}});
			}
		}
	}
}

void sol(){
	dijkstra();
	int ans=inf;
	for(int i=0;i<=k;i++){
		ans=min(ans,dis[n][i]);
	}
	cout<<ans;
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
注意，37行的判断条件一定要将j+1<=k的判断写前边，否则会优先判断dis[v][j+1]>dis[x][j]+z/2导致访问非法内存
https://www.luogu.com.cn/problem/P4822
*/
