#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 1e5;
vector<bool> is_prime(mxn + 1, true);
int a[10], vis[10];
bool found;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= mxn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= mxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void dfs(int num, int used) {
    if (used == (1 << 5) - 1) {
        if (!is_prime[num]) {
            cout << num << '\n';
            found = true;
        }
        return;
    }
    
    for (int i = 0; i < 5 && !found; i++) {
        if (!(used & (1 << i))) {
            if (num == 0 && a[i] == 0) continue;
            dfs(num * 10 + a[i], used | (1 << i));
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 4; i >= 0; i--) {
            a[i] = n % 10;
            n /= 10;
        }
        
        found = false;
        dfs(0, 0);
        if (!found) cout << -1 << '\n';
    }
    return 0;
}
/*
https://codeforces.com/gym/105158/attachments/download/25503/problemset_codeforces.pdf
*/
