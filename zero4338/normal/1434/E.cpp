#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=1e5+5;
const int maxm=500;
int T,n;
int ans;
int a[maxn];
int f[maxm][maxn],nxt[maxn];bool vis[maxm];
struct dsu
{
	int fa[maxm][maxn];
	void prework(){for(int i=0;i<maxm;i++)for(int j=1;j<=n;j++)fa[i][j]=j;}
	int get(int k,int x){return x==fa[k][x]?x:fa[k][x]=get(k,fa[k][x]);}
	void change(int k,int l,int r,int val){for(int i=get(k,r);i>=l;i=get(k,i))fa[k][i]=i-1,f[k][i]=val;}
}S;
void calc()
{
	S.prework();memset(vis,0,sizeof vis);
	int ret=0;
	for(int i=0;i<maxm;i++)for(int j=1;j<=n;j++)f[i][j]=0;
	for(int i=0;i<n;i++)for(int j=a[i];j<a[i+1];j++)nxt[j]=i+1;
	for(int i=n;i>=1;i--)
	{
		int ls=1,po=n;
		for(int j=0;j<maxm;j++)
		{
			if(!f[j][i]){S.change(j,ls,i-1,i);vis[j]=1;break;}
			po=min(po,f[j][i]);int x=2*a[i]-a[po],p=x<0?1:nxt[x];
			S.change(j,ls,p-1,i);ls=p;
		}
	}
	for(int i=0;i<maxm;i++)if(!vis[i]){ans^=i;return;}
}
int main()
{
	T=read();
	while(T--){n=read();for(int i=1;i<=n;i++)a[i]=read();calc();}
	printf("%s",ans?"YES":"NO");
	return 0;
}