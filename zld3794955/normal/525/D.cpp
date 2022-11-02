#include<bits/stdc++.h>
using namespace std;
const int N=2010,M=2010,x_[8]={0,1,0,-1,1,1,-1,-1},y_[8]={1,0,-1,0,-1,1,1,-1};
char c[N][M]={};
int n,m;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("\n%s",c[i]+1);
}
void dfs(int x,int y)
{
	if(x<=0 || y<=0 || x>=n || y>=m)
		return;
	if((c[x][y]=='.')+(c[x+1][y]=='.')+(c[x][y+1]=='.')+(c[x+1][y+1]=='.')==3)
	{
		c[x][y]=c[x+1][y]=c[x][y+1]=c[x+1][y+1]='.';
		for(int k=0;k<8;++k)
			dfs(x+x_[k],y+y_[k]);
	}
}
void work()
{
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)
			dfs(i,j);
	for(int i=1;i<=n;++i)
		puts(c[i]+1);
}
int main()
{
	init();
	work();
	return 0;
}