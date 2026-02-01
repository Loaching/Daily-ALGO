#include<bits/stdc++.h>
using namespace std;
int n;
struct nde{
	int beg,ed;
}t[1008];
int cmp(nde a,nde b){
	if(a.ed==b.ed)	return a.beg<b.beg;
	return a.ed<b.ed;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>t[i].beg>>t[i].ed;
	sort(t+1,t+1+n,cmp);
	int k=1,ans=1,now=1;
	while(k<=n){
		if(t[k].beg>=t[now].ed){
			ans++;
			now=k;
		}
		k++;
	}
	cout<<ans;
	return 0;
}
/*
http://ybt.ssoier.cn:8088/problem_show.php?pid=1422
经典贪心，无需多言
*/
