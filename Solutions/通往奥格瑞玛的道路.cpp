#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX;
vector<vector<pair<int,int>>> G;
vector<int>dis,vis;
vector<int>f;
int mxn=-inf,mnn=inf;
int n,m,b;

void init(){
	cin>>n>>m>>b;
	G.resize(n+1);
	f.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>f[i];
		mnn=min(mnn,f[i]);
		mxn=max(mxn,f[i]);
	}
	for(int i=1,u,v,z;i<=m;i++){
		cin>>u>>v>>z;
		G[u].emplace_back(v,z);
		G[v].emplace_back(u,z);
	}
}

bool dijkstra(int lmt){
	if(f[1]>lmt)	return	false;
	int st=1;
	priority_queue<pair<int,int>> q;
	dis.assign(n+1,inf);
	vis.assign(n+1,0);
	q.push({0,st});
	dis[st]=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])	continue;
		vis[x]=1;
		for(auto p : G[x]){
			int v=p.first,z=p.second;
			if(f[v]>lmt)	continue;	
			if(dis[v]>dis[x]+z){
				dis[v]=dis[x]+z;
				q.push({-dis[v],v});
			}
		}
	}
	return dis[n]<=b;
}

void sol(){
	int ans=-9,le=mnn,ri=mxn;
	while(le<=ri){
		int mid=(le+ri)/2;
		if(dijkstra(mid)){
			ans=mid;
			ri=mid-1;
		}else{
			le=mid+1;
		}
	}
	if(ans<0)		cout<<"AFK";
	else			cout<<ans;
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
给我好好读完题再做啊！！！
https://www.luogu.com.cn/problem/P1462
*/
