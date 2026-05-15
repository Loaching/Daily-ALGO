#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<pair<int,int>>a;
void sol(){
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    int ans=0, pos=0, yu=0;
    for(auto x : a){
        if(x.second > pos){
            int coins = x.second - pos + yu;
            ans += coins / x.first;
            yu = coins % x.first;
            pos = x.second;
        }
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
    return 0;
}
/*
https://codeforces.com/gym/105158/attachments/download/25503/problemset_codeforces.pdf
*/
