#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

void solve() {
	stack<int>s;
    int n;
    string o;
    cin>>n;
    while(n--){
        cin>>o;
        if(o=="push"){
            int k;
            cin>>k;
            s.push(k);
        }
        if(o=="query"){
            if(s.size())    cout<<s.top()<<'\n';
            else            cout<<"Anguei!\n";
        }
        if(o=="size")    cout<<s.size()<<'\n';
        if(o=="pop"){
            if(s.size())    s.pop();
            else            cout<<"Empty\n";
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int T=1;
    cin>>T;
    while(T--)	solve();

	return 0;
}
/*
https://www.luogu.com.cn/problem/B3614
*/
