#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<vector<int>>G;
vector<int>deg(256), vis(256);

int check() {
    vector<int> tmp = deg;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == 0) q.push(i);
    }
    vector<char> order;
    bool unique = true;
    while (!q.empty()) {
        if (q.size() > 1) unique = false;
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : G[u]) {
            if (--tmp[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() < n) return 2;
    if (unique) return 1;
    return 0;
}

void sol() {
    cin >> n >> m;
    G.assign(256, vector<int>());
    deg.assign(256, 0);
    vis.assign(256, 0);

    for (int i = 1; i <= m; i++) {
        char ooo[3];
        cin >> ooo;
        int u = ooo[0] - 'A', v = ooo[2] - 'A';
        G[u].push_back(v);
        deg[v]++;
        vis[u] = vis[v] = 1;

        int state = check();
        if (state == 2) {
            cout << "Inconsistency found after " << i << " relations.\n";
            return;
        }
        if (state == 1) {
            vector<int> tmp = deg;
            queue<int> q;
            for (int j = 0; j < n; j++)
                if (tmp[j] == 0) q.push(j);
            string seq;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                seq.push_back(char(u + 'A'));
                for (int v : G[u]) {
                    if (--tmp[v] == 0) q.push(v);
                }
            }
            cout << "Sorted sequence determined after " << i << " relations: " << seq << ".\n";
            return;
        }
    }
    cout << "Sorted sequence cannot be determined.\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) sol();
    return 0;
}
//https://www.luogu.com.cn/problem/P1347
