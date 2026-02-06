#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LONG_LONG_MAX;
int n,m,k;
const int p = 1e9+7;
vector<int>fac(3000000), inv(3000000), invs(3000000);
void init(int mxn) {
	fac[0] = 1;
	inv[0] = inv[1] = 1;
	invs[0] = 1;
	for (int i = 1; i <= mxn; i++)	fac[i] = i * fac[i - 1] % p;
	for (int i = 2; i <= mxn; i++)	inv[i] = (p - p / i) * inv[p % i] % p;
	for (int i = 1; i <= mxn; i++)	invs[i] = inv[i] * invs[i - 1] % p;
}
int con(int b, int a) {
	if (b > a) return 0;
	return fac[a] * invs[b] % p * invs[a - b] % p;
}
void sol(){
	int ans=0;
	cin>>n>>m>>k;
	vector<int>a;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	vector<int>L(n+1);
	int l=0,r=0;
	while(r < n){
		if (a[r] - a[l] <= k) {
			ans += con(m - 1, r - l);
			ans%=p;
			r++;
		} else l++;
	}
	cout<<ans%p<<'\n';
}
signed main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	init(2000000);
	while(T--){
		sol();
	}
	return 0;
}
/*
不难，但一定注意组合数的写法......
尤其是钦定最后一个数一定被选中的思想务必记牢
https://codeforces.com/problemset/problem/1462/E2
*/
