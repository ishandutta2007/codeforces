#include<iostream>
#include<cstdio>
#define int long long 
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=1e3+5;
int n,m,q;
int ans;
int f[maxn][maxn],g[maxn][maxn];
bool sta[maxn][maxn];int num;
void change(int x,int y)
{
	if(sta[x][y])
	{
		num++;sta[x][y]=0;
		int nowx=x,nowy=y,d=1;bool turn=0;
		while(nowx<=n&&nowy<=m)
		{
			if(!turn)
			{
				if(nowx==n||sta[nowx+1][nowy])break;
				nowx++;d++;
			}
			else
			{
				if(nowy==m||sta[nowx][nowy+1])break;
				nowy++;d++;
			}
			turn=!turn;
		}
		g[x][y]=d;ans+=d;
		nowx=x,nowy=y;turn=1;d=1;
		while(nowx<=n&&nowy<=m)
		{
			if(!turn)
			{
				if(nowx==n||sta[nowx+1][nowy])break;
				nowx++;d++;
			}
			else
			{
				if(nowy==m||sta[nowx][nowy+1])break;
				nowy++;d++;
			}
			turn=!turn;
		}
		f[x][y]=d;ans+=d;
		nowx=x,nowy=y;turn=0;d=0;
		while(nowx>=1&&nowy>=1)
		{
			if(!turn)
			{
				if(nowx==1||sta[nowx-1][nowy])break;
				nowx--;d++;ans+=max(0ll,d+f[x][y]-g[nowx][nowy]);g[nowx][nowy]=max(g[nowx][nowy],d+f[x][y]);
			}
			else
			{
				if(nowy==1||sta[nowx][nowy-1])break;
				nowy--;d++;ans+=max(0ll,d+f[x][y]-f[nowx][nowy]);f[nowx][nowy]=max(f[nowx][nowy],d+f[x][y]);
			}
			turn=!turn;
		}
		nowx=x,nowy=y;turn=1;d=0;
		while(nowx>=1&&nowy>=1)
		{
			if(!turn)
			{
				if(nowx==1||sta[nowx-1][nowy])break;
				nowx--;d++;ans+=max(0ll,d+g[x][y]-g[nowx][nowy]);g[nowx][nowy]=max(g[nowx][nowy],d+g[x][y]);
			}
			else
			{
				if(nowy==1||sta[nowx][nowy-1])break;
				nowy--;d++;ans+=max(0ll,d+g[x][y]-f[nowx][nowy]);f[nowx][nowy]=max(f[nowx][nowy],d+g[x][y]);
			}
			turn=!turn;
		}
	}
	else
	{
		num--;sta[x][y]=1;
		ans-=f[x][y];ans-=g[x][y];
		f[x][y]=g[x][y]=0;
		int nowx=x,nowy=y;bool turn=1;int d=0;
		while(nowx>=1&&nowy>=1)
		{
			if(!turn)
			{
				if(nowx==1||sta[nowx-1][nowy])break;
				nowx--;d++;ans-=g[nowx][nowy]-d;g[nowx][nowy]=d;
			}
			else
			{
				if(nowy==1||sta[nowx][nowy-1])break;
				nowy--;d++;ans-=f[nowx][nowy]-d;f[nowx][nowy]=d;
			}
			turn=!turn;
		}
		nowx=x,nowy=y;turn=0;d=0;
		while(nowx>=1&&nowy>=1)
		{
			if(!turn)
			{
				if(nowx==1||sta[nowx-1][nowy])break;
				nowx--;d++;ans-=g[nowx][nowy]-d;g[nowx][nowy]=d;
			}
			else
			{
				if(nowy==1||sta[nowx][nowy-1])break;
				nowy--;d++;ans-=f[nowx][nowy]-d;f[nowx][nowy]=d;
			}
			turn=!turn;
		}
	}
}
signed main()
{
	n=read();m=read();q=read();num=n*m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int dx=n-i,dy=m-j;
			f[i][j]=2*min(dx,dy)+(dy>dx)+1;
			g[i][j]=2*min(dx,dy)+(dx>dy)+1;
			ans+=f[i][j]+g[i][j];
		}
	}
	while(q--)
	{
		int x=read(),y=read();
		change(x,y);
		printf("%lld\n",ans-num);
	}
	return 0;
}