#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

const int N = 2e5 + 5;
int n;
vector<pair<int, int>> r;
int ma, mb, S;

bool ok(int H, int W) {
    multiset<pair<int, int>> mh, mw;
    for (auto p : r) {
        mh.insert(p);
        mw.insert({p.second, p.first});
    }
    int ch = H, cw = W;
    while (mh.size() > 1) {
        auto it = mh.lower_bound({ch, 0});
        if (it != mh.end() && it->first == ch) {
            int b = it->second;
            if (b >= cw) return 0;
            cw -= b;
            mw.erase(mw.lower_bound({b, ch}));
            mh.erase(it);
        } else {
            auto iw = mw.lower_bound({cw, 0});
            if (iw != mw.end() && iw->first == cw) {
                int a = iw->second;
                if (a >= ch) return 0;
                ch -= a;
                mh.erase(mh.lower_bound({a, cw}));
                mw.erase(iw);
            } else return 0;
        }
    }
    auto [a, b] = *mh.begin();
    return a == ch && b == cw;
}

void sol() {
    cin >> n;
    r.resize(n);
    ma = mb = S = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        r[i] = {a, b};
        S += a * b;
        ma = max(ma, a);
        mb = max(mb, b);
    }
    vector<pair<int, int>> ans;
    if (S % ma == 0) {
        int H = ma, W = S / ma;
        if (ok(H, W)) ans.push_back({H, W});
    }
    if (S % mb == 0) {
        int W = mb, H = S / mb;
        if (H != ma || W != S / ma) {
            if (ok(H, W)) ans.push_back({H, W});
        }
    }
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) sol();
    return 0;
}
//https://www.luogu.com.cn/problem/CF1819B
