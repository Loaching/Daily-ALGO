#include<bits/stdc++.h>
#define int long long 
using namespace std;

bool flag=0;
bool vis[1005][1005];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dr[4][2]={{1,1},{-1,1},{-1,1},{1,-1}};
char a[1005][1005];
void bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push({x,y});
	while(q.size()){
		int nx=q.front().first,ny=q.front().second;
		int xx,yy;
		q.pop();
		for(int i=0;i<4;i++){
			xx=nx+dir[i][0];
			yy=ny+dir[i][1];
			if((a[xx][yy]=='#') and ((a[xx-1][yy]=='#'&&a[xx][yy-1]=='#'&&a[xx-1][yy-1]=='.') or (a[xx-1][yy]=='#'&&a[xx][yy+1]=='#'&&a[xx-1][yy+1]=='.') or (a[xx+1][yy]=='#'&&a[xx][yy-1]=='#'&&a[xx+1][yy-1]=='.') or (a[xx+1][yy]=='#'&&a[xx][yy+1]=='#'&&a[xx+1][yy+1]=='.')))	flag=1;
			if(flag)	return;
			if(!vis[xx][yy]&&a[xx][yy]=='#'){
				q.push({xx,yy});
				vis[xx][yy]=true;
			}
		}
	}
}

signed main(){
	int r,c,ans=0;
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>a[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(a[i][j]=='#'	&& !vis[i][j]){
				ans++;
				bfs(i,j);
			}
	if(flag)	cout<<"Bad placement.";
	else		cout<<"There are "<<ans<<" ships.";
	return 0;
}
/*
这什么题啊纯麻烦
https://www.luogu.com.cn/problem/P1331
*/
