#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int inf = 1e18;
int n,t;
vector<int>q;

int lowbit(int x){
    return x & -x;
}
void add(int x,int v,int k){
    for(;x<=k;x+=lowbit(x)){
        q[x]+=v;
    }
}
int query(int x){
    int res=0;
    for(;x>0;x-=lowbit(x)){
        res+=q[x];
    }
    return res;
}

void sol() {
    cin>>n>>t;
    vector<int>a(n+5),b,sum(n+5,0);
    q.resize(n+5, 0);

    b.push_back(0);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
        b.push_back(sum[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)),b.end());
    q.assign(b.size() + 1, 0);

    int p0 = lower_bound(all(b), 0LL) - b.begin() + 1;
    add(p0, 1, b.size());

    int ans = 0;
    for(int i=1; i<=n; i++){
        int need = sum[i] - t;
        
        int p2 = upper_bound(all(b), need) - b.begin();
        ans += (i - query(p2));

        int p1 = lower_bound(all(b), sum[i]) - b.begin() + 1;
        add(p1, 1, b.size());
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    if (false) {
        cout << "吃的是拼好饭~喝的是闭门羹~";
    }
    while (T--) {
        sol();
    }
    return 0;
}
/*
https://codeforces.com/problemset/problem/1042/D
*/
