#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 100100
#define M 1000000007
using namespace std;

ll n,m,ans,a[N],b[N],c[N],fa[N<<1];
char str[2];
map<P,bool>mm;

ll ff(ll u){return u==fa[u]?u:fa[u]=ff(fa[u]);}

inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}

inline void GG()
{
	puts("0");
	exit(0);
}

inline P zh(ll p,ll q)
{
	if(p>q) swap(p,q);
	if(p+q>n+1) swap(p,q),p=n-p+1,q=n-q+1;
	return mp(p,q);
}

int main()
{
	ll i,j,k,p,q;
	cin>>n>>m;
	for(i=1; i<=m; i++)
	{
		scanf("%lld%lld%s",&p,&q,str);
		a[i]=zh(p,q).fi;
		b[i]=zh(p,q).se;
		c[i]=(str[0]=='x'?0:1);
		if(mm.count(mp(a[i],b[i]))) if(mm[mp(a[i],b[i])]!=c[i]) GG();
			else mm[mp(a[i],b[i])]=c[i];
	}
	for(i=0; i<=n*2+1; i++) fa[i]=i;
	for(i=1; i<=m; i++)
	{
		p=b[i]-a[i]-1,q=a[i]+b[i]-1;
		if(c[i])
		{
			if(p<1) fa[ff(q)]=ff(n*2+1),fa[ff(q+n)]=ff(0);
			else fa[ff(p)]=ff(q+n),fa[ff(p+n)]=ff(q);
		}
		else
		{
			if(p<1) fa[ff(q)]=ff(0),fa[ff(q+n)]=ff(n*2+1);
			else fa[ff(p)]=ff(q),fa[ff(p+n)]=ff(q+n);
		}
	}
	for(i=1; i<=n; i++) if(ff(i)==ff(i+n)) GG();
	if(ff(0)==ff(n*2+1)) GG();
	for(i=0; i<=n*2+1; i++) if(i==fa[i]) ans++;
	cout<<po(2,ans/2-1);
}