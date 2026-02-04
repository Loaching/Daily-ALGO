#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>a,b;
int n;
void init(){
	cin>>n;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		b.push(-k);
		a.push(k);
	}
}
void sol(){
	while(a.size()>1){
		int p=a.top();
		a.pop();
		int q=a.top();
		a.pop();
		a.push(p*q+1);
	}
	
	while(b.size()>1){
		int p=-b.top();
		b.pop();
		int q=-b.top();
		b.pop();
		b.push(-p*q-1);
	}
	
	cout<<-(a.top()+b.top());
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	sol();
	return 0;
}
/*
太简单了不？
http://ybt.ssoier.cn:8088/problem_show.php?pid=1427
*/
