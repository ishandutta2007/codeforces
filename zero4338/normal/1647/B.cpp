#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=105;
int n,m;
bool a[maxn][maxn],vis[maxn][maxn];
int xmi,xmx,ymi,ymx,cnt;
void dfs(int x,int y)
{
	cnt++;
	xmi=min(xmi,x);xmx=max(xmx,x);
	ymi=min(ymi,y);ymx=max(ymx,y);
	vis[x][y]=1;
	if(a[x-1][y]&&!vis[x-1][y])dfs(x-1,y);
	if(a[x+1][y]&&!vis[x+1][y])dfs(x+1,y);
	if(a[x][y+1]&&!vis[x][y+1])dfs(x,y+1);
	if(a[x][y-1]&&!vis[x][y-1])dfs(x,y-1);	
}
int main()
{
	T=read();
	while(T--)
	{
		
		n=read();m=read();
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for(int j=0;j<m;j++)a[i][j+1]=(s[j]-'0');
		}
		bool flag=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!vis[i][j]&&a[i][j])
				{
					xmi=xmx=i;ymi=ymx=j;cnt=0;
					dfs(i,j);
					if(cnt!=(xmx-xmi+1)*(ymx-ymi+1))flag=0;
				}
		puts(flag?"YES":"NO");
	}
	return 0;
}