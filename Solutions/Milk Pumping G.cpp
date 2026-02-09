#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct nde{
    int v,c,f;
};
vector<nde>G[1500];
bool vis[1005];

struct dt{
    double rat;     //性价比
    int mif, smc;   //最小流量，价格
}dist[1005];

priority_queue<pair<double,int>>q;

void init(){
    cin>>n>>m;
    for(int i=1,a,b,c,f;i<=m;i++){
        cin>>a>>b>>c>>f;
        G[a].emplace_back((nde){b,c,f});
        G[b].emplace_back((nde){a,c,f});
    }
}

void dijkstra(){
    for(int i=1;i<=n;i++) dist[i].rat=0;
    dist[1].rat=1e9;
    dist[1].mif=1e9;
    dist[1].smc=0;
    q.push({0,1});
    
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        
        for(auto &e:G[u]){
            int v=e.v, c=e.c, f=e.f;
            int nomin=min(dist[u].mif,f);
            int nosum=dist[u].smc+c;
            double norat=1.0*nomin/nosum;
            
            if(!vis[v] && norat>dist[v].rat){
                dist[v].mif=nomin;
                dist[v].smc=nosum;
                dist[v].rat=norat;
                q.push({norat,v});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    dijkstra();
    
    cout<<(int)(dist[n].rat*1000000);
    
    return 0;
}
/*
https://www.luogu.com.cn/problem/P5837
别想得太复杂了，就是普通dijkstra的dist存下所有而已......
这么简单还得问问AI我是不是没救了
*/
