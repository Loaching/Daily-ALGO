#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans,m;
int fa[1000005],u[1000005],v[1000005];

int get(int x){
	if(x==fa[x])	return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y){
	fa[get(y)]=get(x);
}

int qpow(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)	cin>>u[i]>>v[i];
	for(int i=1;i<=m;i++)	fa[i]=i;
}

void sol(){
	int poc=n;
	for(int i=m;i>=1;i--){
		if(get(u[i])==get(v[i]))	continue;
		if(poc>2){
			merge(u[i],v[i]);
			poc--;
		}else{
			ans=ans+qpow(2,i);
			ans%=mod;
		}
	}
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://atcoder.jp/contests/abc447/tasks/abc447_e
*/
