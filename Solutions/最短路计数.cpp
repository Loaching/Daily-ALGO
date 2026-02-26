#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,m;
int st;
vector<int>G[4000026];
vector<int>dst(4000026,998244353),de(4000005,1);
bool vis[4000005];
const int p=100003;
void init(){
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	st=1;
	de[1]=1;
}
void dijkstra(){
	priority_queue<pair<int,int> >q;
	dst[st]=0;
	q.push(make_pair(0,st));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])	continue;
		vis[x]=1;
		for(int i=0;i<G[x].size();i++){
			int y=G[x][i];
			if(dst[y]==dst[x]+1){
				de[y]+=de[x];
				de[y]%=p;
			}	
			if(dst[y]>dst[x]+1){
				de[y]=de[x];
				dst[y]=dst[x]+1;
				q.push(make_pair(-dst[y],y));
			}
		}
	}
}

void sol(){
	dijkstra();
	for(int i=1;i<=n;i++){
		if(dst[i]==998244353)	cout<<"0\n";
		else					cout<<de[i]%p<<'\n';
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1144
md建无向图
害的我去讨论区丢人现眼
*/
