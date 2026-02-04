#include<bits/stdc++.h>
using namespace std;
const int mod=19260817;
string a,b;
long long A,B;
long long qpow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>a>>b;
	for(char c:a)	A=(A*10+c-'0')%mod;
	for(char c:b)	B=(B*10+c-'0')%mod;
	if(B==0){
		cout<<"Angry!";
		return 0;
	}
	cout<<A*qpow(B,mod-2)%mod;
	return 0;
}
/*
https://www.luogu.com.cn/problem/P2613
# 不要被题目的表象骗了啊口牙！！！
*/
