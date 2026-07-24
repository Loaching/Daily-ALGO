#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 200005;
int n,m;
vector<int>a;
vector<vector<int>>G;
int low[N],dfn[N],ins[N];
stack<int>s;
int tim=0,scn=0,bel[N],sum[N];
int cnt[N];
void dfs(int u,int fa){
	low[u]=dfn[u]=++tim;
	s.push(u);
	ins[u] = true;
	for(auto v : G[u]){
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else{
			if(ins[v]) low[u]=min(low[u],dfn[v]); 
		}
	}
	if(low[u]==dfn[u]){
		scn++;
		sum[scn]=1e18; cnt[scn]=0; 
		int v;
		do{
			v=s.top();
			s.pop();
			if(a[v] < sum[scn]){
				sum[scn] = a[v];
				cnt[scn] = 1;
			}else if(a[v] == sum[scn]){
				cnt[scn]++;
			}
			bel[v]=scn;
			ins[v]=false;
		}while(v != u);
	}
}

void sol() {
	cin>>n;
	a.resize(n+1);
	for(int i=1;i<=n;i++)	cin>>a[i];
	cin>>m;
	G.resize(n+1);
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i,0);
	vector<vector<int>>h(scn+1);
	for(int i=1;i<=n;i++){
		for(int v : G[i]){
			if(bel[i]!=bel[v]){
				h[bel[i]].push_back(bel[v]);
			}
		}
	}
	for(int i=1;i<=scn;i++)	h[i].erase(unique(all(h[i])),h[i].end());
	
	int ans = 0, num = 1;
	for(int i=1;i<=scn;i++){
		ans += sum[i];
		num = (num * cnt[i]) % 1000000007;
	}
	cout << ans << " " << num << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) sol();
	return 0;
}
//https://www.luogu.com.cn/problem/CF427C
