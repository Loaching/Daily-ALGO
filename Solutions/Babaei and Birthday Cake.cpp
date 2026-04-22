#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
#define PI acos(-1)
using namespace std;

int n;
struct cake {
    int k, v;
}a[100005];

vector<int> t;

int lowbit(int x) {
    return x & -x;
}
void add(int k, int x, int v) {
    for (; x <= k; x += lowbit(x)) {
        t[x] = max(t[x], v);
    }
}
int query(int x) {
    int res = 0;
    for (; x > 0; x -= lowbit(x)) {
        res = max(t[x], res);
    }
    return res;
}

void sol() {
    cin >> n;
    vector<int> c(n + 5);
    vector<int> dp(n + 5);
    for (int i = 1, h, r; i <= n; i++) {
        cin >> r >> h;
        a[i] = {i, r * r * h}; 
    }
    vector<int> b;
    for (int i = 1; i <= n; i++)    b.push_back(a[i].v);
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    int m = b.size();
    t.assign(m + 5, 0);
    for (int i = 1; i <= n; i++)   c[i] = lower_bound(all(b), a[i].v) - b.begin() + 1;
    for (int i = 1; i <= n; i++)   dp[i] = a[i].v;
    for (int i = 1; i <= n; i++) {
        int best = query(c[i] - 1);
        dp[i]+=best;
        add(m,c[i],dp[i]);
    }
    int mxn = 0;
    for (int i = 1; i <= n; i++) {
        mxn = max(mxn, dp[i]);
    }

    double ans = mxn * PI;
    printf("%.12lf\n", ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sol();
    return 0;
}
/*
https://www.luogu.com.cn/problem/CF629D
*/
