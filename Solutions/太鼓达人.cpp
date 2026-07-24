#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

int k;

void sol() {
    cin >> k;
    int m = 1 << k;         
    cout << m << " ";
    if (k == 1) {    
        cout << "01\n";
        return;
    }
    int n = 1 << (k - 1);   
    vector<vector<bool>> vis(n, vector<bool>(2, false));
    vector<int> pth;

    function<void(int)> dfs = [&](int u) {
        for (int i = 0; i < 2; i++) {  
            if (!vis[u][i]) {
                vis[u][i] = true;
                int v = ((u << 1) | i) & (n - 1);
                dfs(v);
                pth.push_back(i);
            }
        }
    };

    dfs(0);

    for (int i = 1; i < k; i++) cout << 0;
    for (int i = pth.size() - 1; i >= k - 1; i--) cout << pth[i];
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) sol();
    return 0;
}
//https://www.luogu.com.cn/problem/P10950
