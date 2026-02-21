#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> t, k;

void init() {
    cin >> n;
    t.resize(n);
    k.resize(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) cin >> k[i];
    sort(t.begin(), t.end());
    sort(k.begin(), k.end());
}

void sol() {
    int l1 = 0, r1 = n - 1;
    int l2 = 0, r2 = n - 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (t[r1] > k[r2]) {
            ans += 200;
            --r1;
            --r2;
        } else if (t[r1] < k[r2]) {
            ans -= 200;
            ++l1;
            --r2;
        } else {
            if (t[l1] > k[l2]) {
                ans += 200;
                ++l1;
                ++l2;
            } else {
                if (t[l1] < k[r2]) ans -= 200;
                ++l1;
                --r2;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    sol();
    return 0;
}
/*
https://www.luogu.com.cn/problem/P1650
*/
