#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<pair<int,int>> G[10050];
int dis[10050],cnt[10050],vis[10500];

void init(){
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,-w});
    }
}

void spfa(int st){
    queue<int>q;
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    vis[st]=1;
    cnt[st]++;
    q.push(st);
    while(q.size()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(auto k : G[x]){
            int y=k.first,z=k.second;
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                if(!vis[y]){
                    vis[y]=1;
                    q.push(y);
                    cnt[y]++;
                    if(cnt[y]>n){
                        cout<<"Forever love";
                        return;
                    }
                }
            }
       }
    }
    cout<<dis[n];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    spfa(1);
    return 0;
}

/*半成品，90分，明天改https://www.luogu.com.cn/problem/P2136*/
