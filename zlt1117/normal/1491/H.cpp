#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define A(x) ((x)%mod)
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int block=300,B=100000/block+1,maxn=1e5+5;
int n,q,fa[maxn],g[maxn],cnt[maxn],tag[maxn],tot;
int posl[maxn],posr[maxn],bel[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),q=gi();
	FOR(i,2,n)fa[i]=gi();
	FOR(i,1,n)bel[i]=(i-1)/block+1;
	tot=(n-1)/block+1;
	FOR(i,1,tot)posl[i]=posr[i-1]+1,posr[i]=min(n,posl[i]+block-1);
	FOR(i,1,n)bel[fa[i]]==bel[i]?g[i]=g[fa[i]]:g[i]=i;
}
inline void update(int l,int r,int x)
{
	FOR(i,l,r)fa[i]=max(fa[i]-x,1);
	l=posl[bel[l]],r=posr[bel[r]];
	FOR(i,l,r)fa[i]=max(fa[i]-tag[bel[l]],1);
	FOR(i,l,r)bel[fa[i]]==bel[i]?g[i]=g[fa[i]]:g[i]=i;
	tag[bel[l]]=0;
}
inline void change(int l,int r,int x)
{
	if(bel[l]==bel[r])update(l,r,x);
	else
	{
		int bl=bel[l],br=bel[r];
		update(l,posr[bl],x);
		update(posl[br],r,x);
		bl++,br--;
		FOR(i,bl,br)
		{
			if(cnt[i]<=B)
			{
				cnt[i]++;
				update(posl[i],posr[i],x);
			}
			else tag[i]+=x;
			tag[i]=min(tag[i],n);
		}
	}
}
int counter=0;
inline int LCA(int u,int v)
{
	while(g[u]!=g[v])
	{
		counter++;
		if(u<v)swap(u,v);
		u=max(fa[g[u]]-tag[bel[u]],1);
	}
	while(u!=v)
	{
		counter++;
		if(u<v)swap(u,v);
		u=max(fa[u]-tag[bel[u]],1);
	}
	return u;
}
inline void solve()
{
	while(q--)
	{
		int t=gi();
		if(t==1)
		{
			int l=gi(),r=gi(),x=gi();
			change(l,r,x);
		}
		else
		{
			int u=gi(),v=gi();
			printf("%d\n",LCA(u,v));
		}
	}
}
int main()
{
//	while(T--)
//	{
		init();
		input();
		solve();
//	}
	return 0;
}