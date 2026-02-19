#include<bits/stdc++.h>
#define int long long 
using namespace std;

int n, a[10][10];
int dp[10][10][10][10];

void init() {
    cin >> n;
    memset(a, 0, sizeof a);
    while (true) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) break;
        a[x][y] = z;
    }
}

void sol() {
    memset(dp, 0, sizeof dp);
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= n; y2++) {
                    int val = max({dp[x1-1][y1][x2-1][y2],
                                   dp[x1-1][y1][x2][y2-1],
                                   dp[x1][y1-1][x2-1][y2],
                                   dp[x1][y1-1][x2][y2-1]});
                    if (x1 == x2 && y1 == y2) {
                        dp[x1][y1][x2][y2] = val + a[x1][y1];
                    } else {
                        dp[x1][y1][x2][y2] = val + a[x1][y1] + a[x2][y2];
                    }
                }
            }
        }
    }
    cout << dp[n][n][n][n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    sol();
    
    return 0;
}
/*
https://www.luogu.com.cn/problem/P1004
*/
