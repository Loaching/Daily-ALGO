#include<bits/stdc++.h>
#define int long long
using namespace std;
//所有区间内重量达标者的数量*价值和之和
//须在O(n log n)内完成
//好熟悉，这必是前缀和吧
vector<int>l(234567),r(234567),w(234567),v(234567);
int n,m,s;

void init(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)   cin>>w[i]>>v[i];
    for(int i=1;i<=m;i++)   cin>>l[i]>>r[i];
}
int liangjianyong=0;
bool check(int mid){
    liangjianyong=0;
    vector<int>stw(n+78),stv(n+91);
    for(int i=1;i<=n;i++){
        stw[i]=stw[i-1]+(w[i]>=mid);
        stv[i]=stv[i-1]+(w[i]>=mid)*v[i];
    }
    for(int i=1;i<=m;i++)    liangjianyong+=(stv[r[i]]-stv[l[i]-1])*(stw[r[i]]-stw[l[i]-1]);
    return liangjianyong>=s;
}

void sol(){
    int ans=LONG_LONG_MAX;
    int le=0,ri=1e18;
    while(le<=ri){
        int mid=(le+ri)>>1;
        if(check(mid)){
            le=mid+1;
            ans=min(ans,abs(liangjianyong-s));
        }else{
            ri=mid-1;
            ans=min(ans,abs(liangjianyong-s));
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
