#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,sum,ans;
vector<int>a(1000005);
int c[1000005];

void init(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],sum=sum+a[i];
	sum/=n;
}

void sol(){
	for(int i=1;i<=n;i++)	c[i]=c[i-1]+(a[i]-sum);
	sort(c+1,c+1+n);
	if(n&1){
		int x=ceil(1.0*n/2);
		for(int i=1;i<=n;i++){
			ans+=abs(c[i]-x);
		}
		cout<<ans;
	}else{
		int x=(c[n/2]+c[n/2+1])/2;
		for(int i=1;i<=n;i++){
			ans+=abs(c[i]-x);
		}
		cout<<ans;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	sol();
	
	return 0;
}
/*
绝妙的数学推理！

假设我们的目标是ave(计算所得之平均数)

设第i个元素的前一个向其转移了x[i]个糖果，并向下一个元素转移了x[i+1]个

则有：
  a[1]+x[n]-x[1]=a[2]+x[1]-x[2]=...=a[n]+x[n-1]-x[n];

移项得：
  x[i]=sum(j=1~i)a[j]-i*ave+x[1]

设c[i]=sum(j=1~i)a[j]-i*ave;

则可将问题转化为x[1]到所有c中元素距离之和的最小值

显而易见

计算中位数即可

http://ybt.ssoier.cn:8088/problem_show.php?pid=1432
*/
