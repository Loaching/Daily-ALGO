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

本题要求从顶点1出发，统计到每个顶点的最短路径数量（模100003）。
由于图是无向且边权为1（即无权图），本质上是求BFS层次中到达各点的最短路径条数。
但代码使用了Dijkstra算法（适用于非负权图，此处等价于BFS）：
- dst[i] 表示从起点1到i的最短距离；
- de[i] 表示从起点1到i的最短路径数目；
- 当松弛边(x→y)时：
   • 若发现更短路径（dst[y] > dst[x]+1），则更新dst[y]并令de[y] = de[x]；
   • 若找到另一条相同长度的最短路径（dst[y] == dst[x]+1），则累加路径数：de[y] += de[x]；
- 注意图中可能存在重边和自环，建图时需完整保留所有边（重边会自然增加路径数）；
- 最终若某点不可达（dst[i]仍为初始大值），输出0；否则输出de[i] mod 100003。
*/
