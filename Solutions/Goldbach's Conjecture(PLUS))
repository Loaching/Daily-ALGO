#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>ods,mew;
int n;
void sve(){
	ods[0]=ods[1]=1;
	for(int i=2;i<=n;i++){
		if(!ods[i])	mew.emplace_back(i);
		for(auto j : mew){
			if(i*j>n)	break;
			ods[i*j]=1;
			if(i%j==0)	break;
		}
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie();
	cin>>n;
	ods.resize(n+1);
	sve();
	if(!ods[n-4]){
		cout<<2<<" "<<2<<" "<<n-4;
		return 0;
	}
	for(int i=1;i<mew.size();i++){      //注意边界！
		for(int j=i;j<mew.size();j++){
			int q=mew[i],p=mew[j];
			if(!ods[n-q-p]){
				cout<<q<<' '<<p<<' '<<n-q-p;
				return 0;
			}
		}
	}
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1579


我总闻到我的房间内有一股臭味，
翻来覆去
开灯关灯
也并未找到臭味的来源；
我找来朋友
寻来警察
拉来邻居
却都说只是一股Toilet Water的味道罢了
哪里有什么臭味？
我倦了
扑在床上
恶臭的味道充斥了鼻腔
我才始发觉：
那是枕头下
  我那腐烂的理想。

*/
