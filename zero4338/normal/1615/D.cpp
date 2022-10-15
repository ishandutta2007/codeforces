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
const int maxn=2e5+5;
int n,m;
struct dsu
{
	int fa[maxn<<1];bool vis[maxn<<1];
	void prework(){for(int i=1;i<=2*n;i++)fa[i]=i,vis[i]=0;}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
}S;
struct edge{int fr,to,val;}e[maxn];
bool d[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		S.prework();
		for(int i=1;i<=n-1;i++)
		{
			int x=read(),y=read(),z=read();
			e[i]={x,y,z};
			if(z!=-1)
			{
				if(__builtin_popcount(z)&1)S.merge(x+n,y),S.merge(x,y+n);
				else S.merge(x,y),S.merge(x+n,y+n);
			}
		}
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read(),v=read();
			if(v)S.merge(x+n,y),S.merge(x,y+n);
			else S.merge(x,y),S.merge(x+n,y+n);
		}
		bool flag=1;
		for(int i=1;i<=n;i++)if(S.get(i)==S.get(i+n))flag=0;
		if(!flag)puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				if(S.vis[S.get(i+n)])d[i]=1;
				else d[i]=0,S.vis[S.get(i)]=1;
			}
			for(int i=1;i<=n-1;i++)
				if(e[i].val==-1)e[i].val=d[e[i].fr]^d[e[i].to];
			for(int i=1;i<=n-1;i++)
				printf("%d %d %d\n",e[i].fr,e[i].to,e[i].val);
		}
	}
	return 0;
}