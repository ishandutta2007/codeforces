#include<bits/stdc++.h>
using namespace std;
struct sizes{
	int val,bh;
	int operator<(const sizes& x)const{
		return val<x.val;
	}
}x[72*72];
char w[72][72];
int vis[72][72],n,m,size=0,sz=1,ans=0,k;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void floodfill(int x,int y,int bh){
	vis[x][y]=bh;
	size++;
	for(int i=0;i<4;++i){
		int nx=dir[i][0]+x;
		int ny=dir[i][1]+y;
		if(nx<1||nx>n||ny<1||ny>m)continue;
		if(w[nx][ny]=='*'||vis[nx][ny])continue;
		floodfill(nx,ny,bh);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%s",w[i]+1);
	for(int i=1;i<=m;++i)if(!vis[1][i]&&w[1][i]=='.')floodfill(1,i,1);
	for(int i=1;i<=n;++i)if(!vis[i][1]&&w[i][1]=='.')floodfill(i,1,1);
	for(int i=1;i<=m;++i)if(!vis[n][i]&&w[n][i]=='.')floodfill(n,i,1);
	for(int i=1;i<=n;++i)if(!vis[i][m]&&w[i][m]=='.')floodfill(i,m,1);
	for(int i=2;i<n;++i)
		for(int j=2;j<m;++j)
			if(!vis[i][j]&&w[i][j]=='.'){
				size=0;floodfill(i,j,sz+1);
				x[++sz].val=size;x[sz].bh=sz;
			}
	sort(x+2,x+sz+1);
	for(int i=2,j=1;j<=(sz-1)-k;++i,++j){
		ans+=x[i].val;
		for(int a=2;a<n;++a)
			for(int b=2;b<m;++b)
				if(vis[a][b]==x[i].bh)w[a][b]='*';
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)puts(w[i]+1);
}