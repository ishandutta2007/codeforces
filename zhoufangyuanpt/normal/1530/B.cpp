#include<cstdio>
#include<cstring>
using namespace std;
int a[110][110];
bool pand(int x,int y){return a[x-1][y-1]||a[x-1][y]||a[x-1][y+1]||a[x][y-1]||a[x][y+1]||a[x+1][y-1]||a[x+1][y]||a[x+1][y+1];}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m;scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			int x=i,y=1;
			if(!pand(x,y))a[x][y]=1;
		}
		for(int i=1;i<=m;i++)
		{
			int x=1,y=i;
			if(!pand(x,y))a[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			int x=i,y=m;
			if(!pand(x,y))a[x][y]=1;
		}
		for(int i=1;i<=m;i++)
		{
			int x=n,y=i;
			if(!pand(x,y))a[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)printf("%d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}