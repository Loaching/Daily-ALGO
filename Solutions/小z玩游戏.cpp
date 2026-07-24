#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

const int N = 100005;
int n, mx;
vector<int> pos[N];
vector<int> G[N];
int w[N], e[N];
int dfn[N], low[N], ins[N], bel[N];
stack<int> s;
int tim, scn;

void dfs(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    s.push(u);
    ins[u] = 1;
    for (int v : G[u]) {
        if (!dfn[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++scn;
        int v;
        do {
            v = s.top(); s.pop();
            bel[v] = scn;
            ins[v] = 0;
        } while (v != u);
    }
}

void sol() {
    cin >> n;
    mx = 1;
    for (int i = 1; i <= n; ++i) { cin >> w[i]; mx = max(mx, w[i]); }
    for (int i = 1; i <= n; ++i) { cin >> e[i]; mx = max(mx, e[i]); }

    for (int i = 1; i <= mx; ++i) { G[i].clear(); pos[i].clear(); }
    for (int i = 1; i <= n; ++i) pos[w[i]].push_back(i);

    vector<bool> ex(mx + 1, 0);
    ex[1] = 1;
    for (int i = 1; i <= n; ++i) ex[e[i]] = 1;

    for (int x = 1; x <= mx; ++x) {
        if (!ex[x]) continue;
        for (int m = x; m <= mx; m += x)
            for (int id : pos[m]) G[x].push_back(e[id]);
    }

    fill(dfn, dfn + mx + 1, 0);
    fill(low, low + mx + 1, 0);
    fill(ins, ins + mx + 1, 0);
    tim = scn = 0;
    for (int i = 1; i <= mx; ++i)
        if (ex[i] && !dfn[i]) dfs(i, 0);

    vector<vector<int>> h(scn + 1);
    for (int u = 1; u <= mx; ++u) {
        if (!ex[u]) continue;
        for (int v : G[u])
            if (bel[u] != bel[v]) h[bel[u]].push_back(bel[v]);
    }
    for (int i = 1; i <= scn; ++i) {
        sort(all(h[i]));
        h[i].erase(unique(all(h[i])), h[i].end());
    }

    vector<bool> vs(scn + 1, 0);
    queue<int> q;
    q.push(bel[1]); vs[bel[1]] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : h[u]) if (!vs[v]) { vs[v] = 1; q.push(v); }
    }

    vector<bool> gd(n + 1, 0);
    for (int x = 1; x <= mx; ++x) {
        if (!ex[x] || !vs[bel[x]]) continue;
        for (int m = x; m <= mx; m += x)
            for (int id : pos[m])
                if (bel[x] == bel[e[id]]) gd[id] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) if (gd[i]) ++ans;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int T; cin >> T;
    while (T--) sol();
    return 0;
}
//https://www.luogu.com.cn/problem/P5676
