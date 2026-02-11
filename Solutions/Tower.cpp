#include<bits/stdc++.h>
#define int long long
using namespace std;
const int gbc=500005;
int n;
vector<int>a(gbc);
vector<vector<int>>dp(3,vector<int>(gbc,-9));

void init(){
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    dp[0][0]=0;
}

void sol(){
    for(int i=1;i<=n;i++){
        int now=i&1,pre=now^1;
        dp[now].clear();
        //是否加入？加入gao还是加入di？
        //dp[i][j]表示前i个积木高度差为j时的最高塔
        for(int j=0;j<=gbc;j++){
            if(dp[pre][j]==-9) continue;
            dp[now][j] = max(dp[now][j], dp[pre][j]);
            dp[now][j + a[i]] = max(dp[now][j + a[i]], dp[pre][j] + a[i]);
            int hgh = max(dp[pre][j], dp[pre][j] - j + a[i]);
            dp[now][abs(j - a[i])] = max(dp[now][abs(j - a[i])], hgh);
        }
    }
    int ans = dp[n&1][0];
    if (ans <= 0) cout << -1;
    else cout << ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    sol();
    
    return 0;
}
//我服了爆内存
//我刚学的滚动优化我能惯着你？
/*
https://www.luogu.com.cn/problem/P1651

滚动优化get!
*/
