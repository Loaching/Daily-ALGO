#include<bits/stdc++.h>
using namespace std;
int n,k,sum=0;
int fa[150015];
int d;
int get(int x){
	if(x==fa[x])	return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	if(get(x)==get(y))	return;
    fa[get(y)]=get(x);
}
void init(){
	for(int i=1;i<=3*n;i++)	fa[i]=i;
}

int main(){
	cin>>n>>k;
	init();
	for(int i=1,x,y;i<=k;i++){
		cin>>d>>x>>y;
		if(x>n or y>n){
			sum++;
			continue;
		}
		if(d==1){
			if(get(x)==get(y+2*n) or get(x)==get(y+n)){
				sum++;
			}
			else{
				merge(get(x),get(y));
				merge(get(x+n),get(y+n));
				merge(get(x+n+n),get(y+n+n));
			}
		}
		else{
			if(get(x)==get(y) or get(x)==get(y+2*n))	sum++;
			else{
				merge(get(x),get(y+n));
				merge(get(x+n),get(y+n+n));
				merge(get(x+n+n),get(y));
			}
		}
	}
	printf("%d",sum);
	return 0;
}
//https://www.luogu.com.cn/problem/P2024
