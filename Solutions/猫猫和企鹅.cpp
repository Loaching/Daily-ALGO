#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, d, ans;
vector<int> G[100005];
int dep[510232];

void init() {
	cin >> n >> d;
	for (int i = 1, u, v; i <= n-1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dep[0]=-1;
}

void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
//	if(dep[u]>d)	return;
//	ans++;
	for(auto k : G[u]){
		if(k==fa)	continue;
		dfs(k,u);
	}
}

void sol(){
	dfs(1,0);
//	cout<<ans;
	for(int i=2;i<=n;i++){
		if(dep[i]<=d){
			ans++;
		}
//		cout<<"nin "<<dep[i]<<'\n';
//		cout<<d;
	}
	cout<<ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P5908
*/
