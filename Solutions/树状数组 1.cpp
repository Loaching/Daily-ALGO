#include<bits/stdc++.h>
using namespace std;
int m,n,a[1008006],c[1008006];
int lowbit(int x){
	return x & -x;
}
int query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]);
	}
	while(m--){
		int p,x,y;
		scanf("%d%d%d",&p,&x,&y);
		if(p==1)	add(x,y);
		else		printf("%d\n",query(y)-query(x-1));
	}
	return 0;
}
/*
https://www.luogu.com.cn/problem/P3374
*/
