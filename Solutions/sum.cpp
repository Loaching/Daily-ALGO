#include<bits/stdc++.h>
using namespace std;
const int md=10007;
#define int long long
int ans=0;
int n,m,num[100005],col[100005],cnt[100005][5][10];
signed main() {					//  color d/s cnti
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)	scanf("%lld",&num[i]);
	for(int i=1; i<=n; i++)	scanf("%lld",&col[i]);
	
	for(int i=1;i<=n;i++){
		int t=i%2;
		ans=ans+ (cnt[col[i]][t][1]*num[i]);//st x[i]*z_num
		ans=ans+ (cnt[col[i]][t][2]*i);//st x_num[i]*z
		ans=ans+ (cnt[col[i]][t][3]);	//x*num[x]
		ans=ans+ (cnt[col[i]][t][4]*i*num[i]);	//n*z*z_num
		ans%=md;
		//
		cnt[col[i]][t][1]+=i;
		cnt[col[i]][t][2]+=num[i];
		cnt[col[i]][t][3]+=num[i]*i;
		cnt[col[i]][t][4]++;
	}
	
	printf("%lld",ans%md);
	return 0;
}
