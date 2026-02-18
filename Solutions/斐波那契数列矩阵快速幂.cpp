#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n;
void mul(int a[2][2],int b[2][2]){
    int c[2][2]={};
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(a,c,sizeof(c));
}

void init(){
    cin>>n;
    if(n<=2){
        cout<<1;
        exit(0);
    }
}

void sol(){
    int a[2][2]={{1,1},{1,0}},r[2][2]={{1,0},{0,1}};
    n-=2;
    for(n ; n ; n>>=1 ){
        if(n&1) mul(r,a);
        mul(a,a);
    }
    cout<<(r[0][0]+r[0][1])%mod;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    init();
    sol();
    
    return 0;
}
/*
https://www.luogu.com.cn/problem/P1961
韩炆宏怒骂龙信越屎山代码太难看
*/
