#include<bits/stdc++.h>
using namespace std;
int n,mxn;
void solve(){
	vector<bool>ods(mxn+1);
	vector<int>mew(mxn+1);
	vector<int>st(mxn+1);
	for(int i=2;i*i<=mxn;i++){
		if(!ods[i]){
			int k=i*i;
			while(k<=mxn){
				ods[k]=1;
				k+=i;
			}
		}
	}	
	
	st[1]=0;
	for(int i=2;i<=mxn;i++)	st[i]=st[i-1]+(!ods[i]);
	
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		if(r>mxn or l<1)	cout<<"Crossing the line\n";
		else	cout<<st[r]-st[l-1]<<'\n';
	}
	
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>mxn;
	solve();
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1865
*/
