#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
int tr[500005][30],cnt[500005],ed[500005];
bitset<500005>vis;
int getid(char k){
	return k-96;
}

int tot=0;
void iet(string s){
	int p=0;
	for(auto ch : s){
		int v=getid(ch);
		if(!tr[p][v])	tr[p][v]=++tot;
		p=tr[p][v];
		cnt[p]++;
	}
	ed[p]++;
}

void fnd(string s){
	int p=0;
	for(auto ch : s){
		int v=getid(ch);
		if(!tr[p][v]){
			cout<<"WRONG\n";
			return;
		}
		p=tr[p][v];
	}
	if(ed[p]==1 && !vis[p]){
		cout<<"OK\n";
		vis[p]=1;
		return;
	}else{
		if(vis[p]){
			cout<<"REPEAT\n";
			return;
		}else{
			cout<<"WRONG\n";
			return;
		}
	}
}

void sol(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		iet(s);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		string s;
		cin>>s;
		fnd(s);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T=1;
//	cin>>T;
	while(T--){
		sol();
	}
	
	return 0;
}
//https://www.luogu.com.cn/problem/P2580
