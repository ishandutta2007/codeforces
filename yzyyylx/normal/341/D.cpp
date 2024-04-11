#include<iostream>
#include<cstdio>
#define ll long long
#define N 1010
using namespace std;

ll n,m,sz[4][N][N];

inline ll fz(ll u,ll v){return u%2*2+v%2;}
inline ll lb(ll u){return u&(-u);}

inline void add(ll u,ll v,ll w)
{
	ll t=fz(u,v),tmp=v;
	for(;u<=n+5;u+=lb(u))
	{
		for(v=tmp;v<=n+5;v+=lb(v))
		{
			sz[t][u][v]^=w;
		}
	}
}

inline ll ask(ll u,ll v)
{
	ll t=fz(u,v),tmp=v,res=0;
	for(;u;u-=lb(u))
	{
		for(v=tmp;v;v-=lb(v))
		{
			res^=sz[t][u][v];
		}
	}
	return res;
}

int main()
{
	ll i,j,o,a,b,c,d,e,t;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&o);
		if(o==2)
		{
			scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
			add(a,b,e),add(a,d+1,e),add(c+1,b,e),add(c+1,d+1,e);
//			for(i=1;i<=n;i++) {for(j=1;j<=n;j++) cout<<sz[3][i][j]<<" ";puts("");}
		}
		else
		{
			scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
			printf("%lld\n",ask(c,d)^ask(a-1,b-1)^ask(a-1,d)^ask(c,b-1));
		}
	}
}