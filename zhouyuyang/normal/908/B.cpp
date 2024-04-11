#include<bits/stdc++.h>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
#define ll long long
using namespace std;
bool vis[5];
int ans,n,m,len,sx,sy,ex,ey;
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1},to[5];
char ds[20001];
char s[201];
bool no[101][101];
inline void bfs(){
	int nx=sx,ny=sy;
	For(i,1,len)
	{
		nx+=dx[to[ds[i]-48]];ny+=dy[to[ds[i]-48]];
		if(no[nx][ny]||nx<1||nx>n||ny<1||ny>m)	return;
		if(nx==ex&&ny==ey)	{ans++;return;}
	}
}
inline void dfs(int x){
	if(x==4)	{bfs();return;}
	For(i,1,4)	if(!vis[i])	to[x]=i,vis[i]=1,dfs(x+1),vis[i]=0;
}
int main(){
	scanf("%d%d",&n,&m); 
	For(i,1,n){
		scanf("\n%s",s+1);
		For(j,1,m){
			if(s[j]=='S')	sx=i,sy=j;
			if(s[j]=='E')	ex=i,ey=j;
			if(s[j]=='#')	no[i][j]=1;
		}
	}
	scanf("\n%s",ds+1);
	len=strlen(ds+1);
	dfs(0);
	cout<<ans<<endl;
}