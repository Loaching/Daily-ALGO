#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000005],cnt[1000005];

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
} 

void sol(){
	int l=0,ans=LONG_LONG_MAX,sl,sr;
	int coun=0;
	for(int r=1;r<=n;r++){
		int x=cnt[a[r]];
		cnt[a[r]]++;
		if(x==0){
			coun++;
		}
		while(coun==m){
			int y=cnt[a[l]];
			cnt[a[l]]--;
			if(y==1)	coun--;
			if(ans>r-l){
				ans=r-l;
				sl=l;sr=r;
			}
			l++;
		}
	}
	cout<<sl<<' '<<sr;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1638
*/
