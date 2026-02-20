#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> t;

void init() {
    cin >> n;
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    sort(t.begin() + 1, t.end());
}

void sol() {
    if (n == 1) {
        cout << t[1];
        return;
    }
    if (n == 2) {
        cout << t[2];
        return;
    }
    if (n == 3) {
        cout << t[1] + t[2] + t[3];
        return;
    }
    int ans = 0;
    int i = n;
    while (i > 3) {
        ans += min(2 * t[2] + t[1] + t[i], 2 * t[1] + t[i] + t[i-1]);
        i -= 2;
    }
    if (i == 3)         ans += t[1] + t[2] + t[3];
    else if (i == 2)    ans += t[2];
    else if (i == 1)    ans += t[1];
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    sol();
    return 0;
}

/*
https://www.luogu.com.cn/problem/P1809
*/
