#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct bke {
    int t, w;
};

bool cmp(bke a, bke b) {
    return a.t > b.t;
}

vector<bke> ac;
priority_queue<int> pq;

void init() {
    cin >> n;
    ac.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ac[i].t >> ac[i].w;
    }
    sort(ac.begin(), ac.end(), cmp);
}

void sol() {
    int ans = 0;
    int j = 0;
    for (int i = ac[0].t; i >= 1; --i) {
        while (j < n && ac[j].t >= i) {
            pq.push(ac[j].w);
            j++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    sol();
    return 0;
}
