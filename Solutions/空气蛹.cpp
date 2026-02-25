#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int inf=100000009;

void sol(){
    int n,m,sum=0;
    vector<int>a;
    cin>>n>>m;
    bool flag=1;
    for(int i=0,x;i<n;i++){
        cin>>x;
        if(i&&x<a.back()) flag=0;
        a.push_back(x);
        sum+=x;
    }
    if(flag){
        cout<<sum<<'\n';
        return ;
    }
    sort(a.begin(),a.end());
    if(a[0]+a[1]-m>0) sum-=(a[0]+a[1])-m;
    cout<<sum<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        sol();
    }
    return 0;
}
/*
穹p好恐怖
https://www.luogu.com.cn/problem/P14057
*/
