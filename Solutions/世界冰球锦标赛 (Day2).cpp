//https://www.luogu.com.cn/problem/P4799
#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
int n;
vector<int>a,an;
void dfs(int k,int sum){
	if(k>n/2){
		an.push_back(sum);
		return;
	}else{
		dfs(k+1,sum+a[k]);
		dfs(k+1,sum);
	}
}
int m,ans;
void dfs2(int k,int sum){
	if(k>n){
		ans+=lower_bound(all(an),m-sum+1)-an.begin();
		return;
	}else{
		dfs2(k+1,sum+a[k]);
		dfs2(k+1,sum);
	}
}
void sol() {
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(1,0);
	sort(all(an));
	dfs2(n/2+1,0);
	cout<<ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1; 
//	cin >> T;
	while (T--) sol();
	return 0;
}
