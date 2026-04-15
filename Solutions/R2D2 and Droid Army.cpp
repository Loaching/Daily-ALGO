#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e18;
int n, m, k;
vector<vector<int>> a;
int st[6][100005][32];

int ask(int p, int str, int ed) {
    if (str > ed) return 0;
    int len = __lg(ed - str + 1);
    return max(st[p][str][len], st[p][ed - (1 << len) + 1][len]);
}

void init() {
    cin >> n >> m >> k;
    a.assign(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            st[i][j][0] = a[j][i];
        }
    }
    for (int p = 1; p <= m; p++) {
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                st[p][j][i] = max(st[p][j][i - 1], st[p][j + (1 << (i - 1))][i - 1]);
            }
        }
    }
}

void solve() {
    int le = 1;
    int lmx = 0, lx = 1, rx = 0;

    for (int ri = 1; ri <= n; ri++) {
        while (le <= ri) {
            int sum = 0;
            for (int i = 1; i <= m; i++) {
                sum += ask(i, le, ri);
            }
            if (sum <= k) break;
            le++;
        }
        if (le <= ri) {
            if (ri - le + 1 > lmx) {
                lmx = ri - le + 1;
                lx = le;
                rx = ri;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ask(i, lx, rx) << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        init();
        solve();
    }
    return 0;
}
/*
https://codeforces.com/problemset/problem/514/D
*/
