#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n;
vector<int>a,b,c;

int lowbit(int x){
	return x & -x;
}

int query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a.resize(n+5);
	b.resize(n+5);
	c.resize(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		add(i,b[i]);
	}
	while(m--){
		int p,x,y,z;
		cin>>p>>x;
		if(p==1){
			cin>>y>>z;
			add(x,z);add(y+1,-z);
		}
		else{
			cout<<query(x)<<'\n';
		}
	}
	return 0;
}
/*
https://www.luogu.com.cn/problem/P3368
*/
