#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int>>G;
vector<int>deg;
bool vis[256][256];
vector<char>ans;

void dfs(int u){
	for(auto v : G[u]){
		if(!vis[u][v]){
			vis[u][v]=vis[v][u]=1;
			dfs(v);
		}
	}
	ans.push_back(u);
}

void sol() {
	cin >> n;
	G.resize(128);
	deg.assign(128,0);
	for(int i=1;i<=n;i++){
		char q[2];
		cin>>q;
//		if(q[0]>q[1])	swap(q[0],q[1]);
		G[q[0]].push_back(q[1]);
		G[q[1]].push_back(q[0]);
		deg[q[0]]++;deg[q[1]]++;
	}
	
	vector<int> odd;
	int mnn = 1e18;
	for(int i=0;i<128;i++){
		if(deg[i]&1) odd.push_back(i);
		if(deg[i]>0) mnn = min(mnn, i);
	}
	
	int sta;
	if(odd.empty()) {
		sta = mnn;
	} else if(odd.size()==2) {
		sta = min(odd[0], odd[1]); 
	} else {
		cout<<"No Solution\n";
		return;
	}
	
	for(int i=0;i<128;i++) sort(G[i].begin(), G[i].end());
	
	dfs(sta);
	
	if(ans.size() != n+1) {
		cout<<"No Solution\n";
		return;
	}
	
	reverse(ans.begin(), ans.end());
	for(char c : ans) cout<<c;
	cout<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) {
		sol();
	}
	return 0;
}
//https://www.luogu.com.cn/problem/P1341
