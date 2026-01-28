#include<bits/stdc++.h>
using namespace std;
long long inv[50000005],n,p;
int main(){
	cin>>n>>p;
	inv[1]=1;
	cout<<'1'<<'\n';
	for(int i=2;i<=n;i++){
		inv[i]=(p-p/i)*inv[p%i]%p;
		cout<<(inv[i]+p)%p<<'\n';
	}
	return 0;
}
//https://www.luogu.com.cn/problem/P3811
