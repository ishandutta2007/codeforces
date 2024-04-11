#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=4e5+5;
struct edge
{
	int u,v,w;
	edge(int uu=0,int vv=0,int ww=0){u=uu,v=vv,w=ww;}
	inline bool operator<(const edge &b)const{return w>b.w;}
}e[maxn];
int n,m,a[maxn],b[maxn],fa[maxn],tot;
ll ans=0;
inline int get(int x){if(x==fa[x])return x;else return fa[x]=get(fa[x]);}
int main()
{
	m=gi(),n=gi();
	FOR(i,1,m)a[i]=gi();
	FOR(i,1,n)b[i]=gi();
	FOR(i,1,n+m)fa[i]=i;
	FOR(i,1,m)
	{
		int s=gi();
		FOR(j,1,s)
		{
			int x=gi();
			e[++tot].u=x;
			e[tot].v=i+n;
			e[tot].w=a[i]+b[x];
			ans+=a[i]+b[x];
		}
	}
	sort(e+1,e+tot+1);
	FOR(i,1,tot)
	{
		int u=get(e[i].u),v=get(e[i].v);
		if(u!=v){fa[u]=v,ans-=e[i].w;}
	}
	printf("%lld\n",ans);
	return 0;
}
///