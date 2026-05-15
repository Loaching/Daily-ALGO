#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int b1=19260817,b2=13331,m=998244353;
int n;
string s;
void sol(){
	cin>>n;
	string ans;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		if(ans.empty()){
			ans=t;
			continue;
		}
		int la=ans.length(),lt=t.length();
		int mx=min(la,lt);
		int ha1=0,ha2=0,ht1=0,ht2=0,p1=1,p2=1;
		int len=0;
		for(int j=0;j<mx;j++){
			ha1=(ha1*b1+ans[la-1-j])%m;
			ha2=(ha2*b2+ans[la-1-j])%m;
			ht1=(ht1+ t[j]*p1)%m;
			ht2=(ht2+ t[j]*p2)%m;
			p1=p1*b1%m;
			p2=p2*b2%m;
			if(ha1==ht1&&ha2==ht2)len=j+1;
		}
		ans+=t.substr(len);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sol();
	return 0;
}
/*
https://www.luogu.com.cn/problem/CF1200E
*/
