//https://www.luogu.com.cn/problem/P1083
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,b[N],r[N],d[N],s[N],t[N],st[N],ans;
bool check(int mid){
	for(int i=1;i<=mid;i++){
		b[s[i]]-=d[i];
		b[t[i]+1]+=d[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+b[i];
		if(b[i]<0)	return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		st[i]=r[i]-r[i-1];
	}
	for(int i=1;i<=m;i++)	scanf("%d%d%d",&d[i],&s[i],&t[i]);
	int le=1,ri=m,mid;
    bool flag=0;
	while(le<=ri){
		for(int i=1;i<=n;i++){
			b[i]=st[i];
		}
		mid=(ri+le)>>1;
		if(check(mid)){
			ri=mid-1;
			ans=mid;
		}
		else{
            le=mid+1;
        }
	}
	if(ans==0)
		printf("0");
	else{
		printf("-1\n%d",ans);
	}
	return 0;
}
