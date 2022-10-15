#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=4e3+5;
int n,m;
int a[maxn];
struct cartesian
{
	int ls[maxn],rs[maxn],rt;
	void build()
	{
		static int sta[maxn],top;
		for(int i=1;i<=n;i++)
		{
			int k=top;
			while(k&&a[sta[k]]>a[i])k--;
			if(k)rs[sta[k]]=i;
			if(!k)rt=i;
			if(k<top)ls[i]=sta[k+1];
			sta[++k]=i;top=k;
		}
	}
	ll f[maxn][maxn];int siz[maxn];
	void dfs(int u)
	{
		siz[u]=1;
		if(ls[u])dfs(ls[u]),siz[u]+=siz[ls[u]];
		if(rs[u])dfs(rs[u]),siz[u]+=siz[rs[u]];
		for(int i=0;i<=siz[ls[u]];i++)
		{
			for(int j=0;j<=siz[rs[u]];j++)
			{
				if(i+j>m)continue;
				f[u][i+j]=max(f[u][i+j],f[ls[u]][i]+f[rs[u]][j]-2ll*i*j*a[u]);
			}
		}
		for(int i=siz[u];i>=1;i--)f[u][i]=max(f[u][i],f[u][i-1]+(ll)(m-2*i+1)*a[u]);
	}
}tr;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	tr.build();
	tr.dfs(tr.rt);
	printf("%lld",tr.f[tr.rt][m]);
	return 0;
}