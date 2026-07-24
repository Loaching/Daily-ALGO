#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N = 200005;
int n,m;
int st;
vector<vector<int>>G;
int low[N],dfn[N],ins[N];

int capbel;

stack<int>s;
int tim=0,scn=0,bel[N],sum[N];
void dfs(int u,int fa){
    low[u]=dfn[u]=++tim;
    s.push(u);
    ins[u] = true;
    for(auto v : G[u]){
        if(!dfn[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }else{
            if(ins[v]) low[u]=min(low[u],dfn[v]); 
        }
    }
    if(low[u]==dfn[u]){
        scn++;
        int v;
        do{
            v=s.top();
            if(v==st)  capbel=scn;
            s.pop();
            bel[v]=scn;
            ins[v]=false;
        }while(v != u);
    }
}


void sol() {
    cin>>n>>m>>st;
    G.resize(n+1);                       // 修正1：n+1 而不是 m+1
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i,0);

    vector<vector<int>>h(scn+1);
    vector<int> indeg(scn+1, 0);          // 新增：统计入度
    for(int i=1;i<=n;i++){
        for(int v : G[i]){
            if(bel[i]!=bel[v]){
                h[bel[i]].push_back(bel[v]);
            }
        }
    }
    for(int i=1;i<=scn;i++){
        h[i].erase(unique(all(h[i])),h[i].end());
        for(int v : h[i]) indeg[v]++;     // 新增：计算入度
    }

    // 新增：从首都所在SCC开始标记可达SCC
    vector<bool> vis(scn+1, false);
    queue<int> q;
    q.push(capbel);
    vis[capbel] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : h[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }

    // 新增：统计未标记且入度为0的SCC数量
    int ans = 0;
    for(int i=1;i<=scn;i++){
        if(!vis[i] && indeg[i]==0) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) sol();
    return 0;
}
//https://www.luogu.com.cn/problem/CF999E
