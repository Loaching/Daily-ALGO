#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,minn=LONG_LONG_MAX;
const int inf = 89474865565;
vector<pair<int,int>> G[10050];

void init(){
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,-w});
    }
}

void spfa(int st,int ed){
    vector<int>dis(10050,inf),cnt(10050,0),vis(10500,0);
    queue<int>q;
    dis[st]=0;
    vis[st]=1;
    cnt[st]=0;
    q.push(st);
    while(q.size()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(auto k : G[x]){
            int y=k.first,z=k.second;
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=n){
                    cout<<"Forever love";
                    exit(0);
                }
                if(!vis[y]){
                    vis[y]=1;
                    q.push(y);
                }
            }
       }
    }
    minn=min(minn,dis[ed]);
}

void sol(){
    spfa(1,n);
    spfa(n,1);
    cout<<minn;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    sol();
    return 0;
}


/*https://www.luogu.com.cn/problem/P2136*/
