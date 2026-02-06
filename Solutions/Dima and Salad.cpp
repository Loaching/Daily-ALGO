#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=8486456486;
int n, k;
vector<int>a(100005), b(100005);
vector<int>m(100005), uh, dw;
vector<int>dp1(1546848,-inf), dp2(1564387,-inf);
int sum1,sum2;
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++)	cin >> b[i];
	for (int i = 1; i <= n; i++) {
		m[i] = a[i] - k * b[i];
		if (m[i] >= 0){	
			uh.push_back(m[i]);
			sum1+=m[i];
		}
		else{
			sum2+=m[i];
			dw.push_back(m[i]);
		}
	}
	dp1[0]=dp2[0]=0;
}

void sol() {
	sum2=-sum2;
	for (int i = 1; i <= n; i++) {
		if(m[i]>=0){
			for(int j=sum1;j>=0	&& j>=m[i];j--){
				dp1[j]=max(dp1[j],dp1[j-m[i]]+a[i]);
			}
		}else{
			for(int j=sum2;j>=0	&& j>=-m[i];j--){
				dp2[j]=max(dp2[j],dp2[j+m[i]]+a[i]);
			}
		}
	}
	
	int ans=-1;
	for(int i=0;i<=max(sum1,sum2);i++){
		if(dp1[i]>0 or dp2[i]>0)	ans=max(ans,dp1[i]+dp2[i]);
	}
	cout<<ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	sol();
	
//	cout<<INFINITY;

	return 0;
}
/*
https://www.luogu.com.cn/problem/CF366C
https://codeforces.com/problemset/problem/366/C
抽象成01背包的过程很厉害
*/
