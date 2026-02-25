#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n/2;i++){
		cout<<"|";
		for(int j=1;j<=n-2;j++)	cout<<"a";
		cout<<"|\n";
	}
	// for(int i=1;i<=n/2;i++){
		cout<<"|";
		for(int j=1;j<=n-2;j++)	cout<<"-";
		cout<<"|\n";
	// }
	for(int i=1;i<=n/2;i++){
		cout<<"|";
		for(int j=1;j<=n-2;j++)	cout<<"a";
		cout<<"|\n";
	}
	return 0;
}
/*
https://www.luogu.com.cn/problem/B3924
?这是图论题啊为什么出现在图论单子里
好弱智
*/
