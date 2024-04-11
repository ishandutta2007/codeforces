#include<cstdio>
#include<algorithm>
using namespace std;
int n,mov[4][2]={1,0,-1,0,0,1,0,-1},m,gr[1005][1005],mi[2][1005],mx[2][1005],cnt[2][1005],tot=0,vis[1005][1005];
char s[1005];
void nope()
{
	printf("-1\n");
	exit(0);
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	int nx=0,ny=0;
	for(int i=0;i<4;i++)
	{
		nx=x+mov[i][0];ny=y+mov[i][1];
		if(nx&&ny&&nx<=n&&ny<=m)
		{
			if(!vis[nx][ny]&&gr[nx][ny])
			{
				dfs(nx,ny);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)mi[0][i]=100000,mx[0][i]=-1;
	for(int i=1;i<=m;i++)mi[1][i]=100000,mx[1][i]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='#')
			{
				gr[i][j]=1;
				cnt[0][i]++;cnt[1][j]++;
				mi[0][i]=min(mi[0][i],j);mx[0][i]=max(mx[0][i],j);
				mi[1][j]=min(mi[1][j],i);mx[1][j]=max(mx[1][j],i);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!vis[i][j]&&gr[i][j])tot++,dfs(i,j);
	for(int i=1;i<=n;i++)
	{
		if(cnt[0][i]&&cnt[0][i]!=mx[0][i]-mi[0][i]+1)nope();
	}
	for(int i=1;i<=m;i++)if(cnt[1][i]&&cnt[1][i]!=mx[1][i]-mi[1][i]+1)nope();
	bool ok0=false,ok1=false;
	for(int i=1;i<=n;i++)if(cnt[0][i]==0)ok0=true;
	for(int i=1;i<=m;i++)if(cnt[1][i]==0)ok1=true;
	if(ok0^ok1)nope();
	printf("%d\n",tot);
	return 0;
}