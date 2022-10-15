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
const int maxn=1e3+5;
int n,a[maxn][maxn];
int cur;bool vis[maxn][maxn];
void cover(int x,int y)
{
	cur^=a[x][y];
	vis[x+1][y]^=1;vis[x-1][y]^=1;
	vis[x][y+1]^=1;vis[x][y-1]^=1;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)generate_n(a[i]+1,n,read);
		for(int i=1;i<=n;i++)memset(vis[i],0,sizeof(bool)*(n+1));
		cur=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!vis[i][j])cover(i+1,j);
		printf("%d\n",cur);
	}
	return 0;
}