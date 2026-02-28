#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, st, minn = LONG_LONG_MAX;
vector<int> dis, siz;
vector<int> G[200008];

void dfs(int u, int fa) {
	dis[u]=dis[fa]+1;
	int mxn = -INT_MAX;
	for (auto v : G[u]) {
		if (v == fa)	continue;
		dfs(v,u);
		siz[u]+=siz[v];
		mxn=max(mxn,siz[v]);
	}
	if(max(n-siz[u],mxn) <= minn){
		if(max(n-siz[u],mxn) == minn){
			st=min(st,u);
			minn=max(n-siz[u],mxn);
		}else{
			st=u;
			minn=max(n-siz[u],mxn);
		}
	}
}

void init() {
	cin >> n;
	siz.assign(n+1,1);
	dis.assign(n+1,0);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v ;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout<<st<<' ';
	dis.assign(n+1,0);
	dis[0]=-1;
	dfs(st,0);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=dis[i];
	}
	cout<<sum;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	// sol();
	
	return 0;
}
/*
弱智题
*/
