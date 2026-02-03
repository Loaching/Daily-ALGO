#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,H,k;
vector<vector<int>>dp(1005,vector<int>(1005,0));
vector<int>les(10005),s(10005),fish(10005);

void init(){
	cin>>n>>H;
	k=H*12;
	for(int i=1;i<=n;i++)	cin>>fish[i];
	for(int i=1;i<=n;i++)	cin>>les[i];
	for(int i=2;i<=n;i++)	cin>>s[i],s[i]+=s[i-1];
}

void sol(){
	int ans=0,mxn=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=fish[i]-j*les[i];
			
	for(int i=1;i<=n;i++){
		ans=0;
		priority_queue<int>www;
		int m=k-s[i];
//		cout<<"bubuybububub "<<m<<endl;
		for(int j=1;j<=i;j++)
			for(int p=0;p<=k;p++)
				www.push(dp[j][p]);
		
		for(int j=1;j<=m;j++){
//			cout<<www.top()<<"\n";
			if(www.top()>=0)	ans+=www.top();
			www.pop();
		}
		
		mxn=max(ans,mxn);
	} 
	cout<<mxn;
}

signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    sol();
    
    return 0;
}
/*
http://ybt.ssoier.cn:8088/problem_show.php?pid=1431
事先就把路程处理掉
其实还可以优化：
              可以一边枚举最后一个池塘一边将fish数入单调队列，可省空间
*/
