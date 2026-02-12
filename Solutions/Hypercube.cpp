#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e9+7;
int a,b;
vector<int> fac(100005), inv(100005) ,invs(100005);
//a有多少b
void init(int mxn){
    fac[0]=1;
    inv[0]=inv[1]=1;
    invs[0]=1;
    for(int i=1;i<=mxn;i++)     fac[i]=fac[i-1]%p*i%p;
    for(int i=2;i<=mxn;i++)     inv[i]=(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=mxn;i++)     invs[i]=invs[i-1]*inv[i]%p;
    
    cin>>a>>b;
}
//n中取m
int con(int n,int m){
    if(m<0||m>n) return 0;
    return fac[n]*invs[m]%p*invs[n-m]%p;
}

int qpow(int x,int y){
    int res=1;
    while(y){
        if(y&1) res=res*x%p;
        x=x*x%p;
        y>>=1;
    }
    return res;
}

void sol(){
    if(a<b){
        cout<<"0";
        return ;
    }
    int ans=con(a,b)*qpow(2,a-b)%p;
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init(100000);
    sol();
    
    return 0;
}
/*
https://www.luogu.com.cn/problem/P1999
数学题
*/
