#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int p=1000000007;

int sum=0;
int n,m;
vector<int> fac(1000005),inv(1000005),invs(1000005);
vector<int> c(2345678);
void init(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>c[i];
        sum+=c[i];
    }
    int r = n - sum - m;
    if(r < 0){
        cout<<0<<'\n';
        exit(0);
    }
    int mxn = r + m;
    fac[0]=1;
    inv[0]=inv[1]=1;
    invs[0]=1;
    for(int i=1;i<=mxn;i++) fac[i]=fac[i-1]*i%p;
    for(int i=2;i<=mxn;i++) inv[i]=(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;i++)   invs[i]=invs[i-1]*inv[i]%p;
}

int con(int a,int b) {
    if(a<0||a>b)return 0;
    return fac[b]*invs[a]%p*invs[b-a]%p;
}   //b中取a

void sol(){
    int r = n - sum - m;
    cout << con(m-1, r+m-1) << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    sol();
    
    return 0;
}
/*
https://www.luogu.com.cn/problem/P1680
弄求简单 
*/
