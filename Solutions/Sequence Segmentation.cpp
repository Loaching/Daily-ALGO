#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int>g(5000005);
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>g[i];
}
void sol(){
	int ans=0;
	for(int i=1;i<=n;){
		int s=0;
		ans++;
		while(s+g[i]<=m && i<=n){
			s+=g[i];
			i++;
		}
	}
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
太简单以至于我不相信自己在做提高篇的题目
http://ybt.ssoier.cn:8088/problem_show.php?pid=1428
*/
