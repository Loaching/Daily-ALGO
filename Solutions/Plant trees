#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nde {
	int st,ed,t;
};
int n,m,ans;
nde p[30005];
vector<int>act(30005,0);

bool cmp(nde a,nde b) {
//	if(a.ed==b.ed)	return a.st<=b.st;
	return a.ed<b.ed;
}

void init() {
	cin>>n>>m;
	for(int i=1; i<=m; i++)	cin>>p[i].st>>p[i].ed>>p[i].t;
}

void sol() {
	sort(p+1,p+1+m,cmp);

	for(int i=1; i<=m; i++) {
		
		int cnt=0,tmp;
		for(int k=p[i].st;k<=p[i].ed;k++)	cnt+=act[k];
		tmp=p[i].t-cnt;
		
		for(int j=p[i].ed; j>=p[i].st && tmp>0;j--){
			
			if(act[j]==1)	continue;
			
			act[j]=1;
			ans++;
			tmp--;
		}
	}
	
//	for(int i=1;i<=n;i++)	cout<<act[i]<<' ';
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
http://ybt.ssoier.cn:8088/problem_show.php?pid=1423
错了好多次...注意细节啊！
*/
