#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,nn,sme=0;
struct bke{
	int t,w;
	double sw;
}; 
bool cmp(bke a,bke b){
	if(a.w==b.w)	return a.t>b.t;
	return a.w>b.w;
}
vector<int>ls(50005);
vector<bke>ac,p(50005);
void init(){
	cin>>m>>n;
	for(int i=1;i<=n;i++)	cin>>ls[i];
	for(int i=1,c;i<=n;i++){
		cin>>c;
		sme+=c;
		ac.push_back({ls[i],c,c*1.0/ls[i]});
	}
	sort(ac.begin(),ac.end(),cmp);
}

void sol(){
	vector<bool>vis(n+5);
	nn=n;
	for(int i=0;i<=n;i++){
		int j=ac[i].t;
		while(vis[j]==1 and j>=0)	j--;
		if(j==0){
			nn--;
			continue;
		}
		p[j]=ac[i];
		vis[j]=1;
	}
	
	int ans=m-sme;
	
	for(int i=1;i<=n;i++)	ans+=p[i].w;
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	sol();
	return 0;
}
/*
http://ybt.ssoier.cn:8088/problem_show.php?pid=1426
还是那句话，注意边界啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
*/
