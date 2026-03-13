#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e15;

int n, m;
vector<vector<pair<int, int>>> G;
vector<int> dis1, dis2;

void init() {
    cin >> n >> m;
    G.assign(n + 1, {});
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w}); 
    }
}

void dijkstra() {
    dis1.assign(n + 1, INF);
    dis2.assign(n + 1, INF);
    priority_queue<pair<int, int>>q;
    dis1[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int d=-q.top().first,u=q.top().second;
        q.pop();
        if (d > dis2[u]) continue; 
        for (auto k : G[u]) {
            int v=k.first,w=k.second;
            int nd = d + w;
            if (nd < dis1[v]) {
                swap(dis1[v], nd); 
                q.push({-dis1[v], v});
            }
            if (nd > dis1[v] && nd < dis2[v]) {
                dis2[v] = nd;
                q.push({-nd, v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();
    dijkstra();
    
    cout << dis2[n] << '\n';
    return 0;
}
/*
https://www.luogu.com.cn/problem/P2865
同时记录到达每个点的最短路和次短路
对于每个点
以前一个点的最短路与次短路共同参与当前点的此段路经更新
嗯对，就是这样
                                 ————————————致我死去的数学
*/
