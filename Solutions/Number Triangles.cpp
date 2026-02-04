#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005][1005],dp[10005][1005],n;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>dp[i][j];
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	cout<<dp[1][1];
	return 0;
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 

*/
//经典题目，无需多言
//https://www.luogu.com.cn/problem/P1216
