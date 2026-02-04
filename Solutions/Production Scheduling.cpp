#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0;
struct aka{
	int dat,num;
};
bool cmp(aka a,aka b){
	return a.dat<b.dat;
}
bool mcp(aka a,aka b){
	return a.dat>b.dat;
}
vector<int>a(10005);
vector<int>b(10005),p(50005);
vector<aka>ca,cb,c;

void init() {
	cin>>n;
	for(int i=1; i<=n; i++)	cin>>a[i];
	for(int i=1; i<=n; i++) {
		cin>>b[i];
		if(a[i]<b[i])	ca.push_back({a[i],i});
		else			cb.push_back({b[i],i});
	}
	sort(ca.begin(),ca.end(),cmp);
	sort(cb.begin(),cb.end(),mcp);
	
	for(auto k:ca)	c.push_back({k.dat,k.num});
	for(auto k:cb)	c.push_back({k.dat,k.num});
}

void sol() {
	int p=0,q=0;
//	for(int i=1;i<=n;i++)	cout<<c[i]<<' ';
//	cout<<'\n';	
	for(int i=0;i<c.size();i++){
		int x=c[i].num;
//		cout<<a[x]<<' '<<b[x]<<'\n';
		p+=a[x];
		 
		q=max(p,q)+b[x];
//		cout<<p<<' '<<q<<'\n';
	}
	cout<<q<<endl;
	
	for(auto k : c)
		cout<<k.num<<' ';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	sol();
	return 0;
}
/*
记住这一个从某一点开始从后往前贪心的思想
我服了居然想了一上午
http://ybt.ssoier.cn:8088/problem_show.php?pid=1425
*/
