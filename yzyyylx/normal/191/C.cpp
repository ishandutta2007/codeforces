#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define lb(x) (x&(-x))
#define N 200100
using namespace std;

ll n,m,bb,first[N],top[N],deep[N],fa[N],num[N];
struct Bn
{
	ll to,next,from;
}bn[N*2];

ll ft(ll u) {return top[u]==u?u:top[u]=ft(top[u]);}

inline void add(ll u,ll v)
{
	bb++;
	bn[bb].from=u;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

ll dfs(ll now,ll last)
{
	ll p,q,res=1,mm=0,mx=0;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		deep[bn[p].to]=deep[now]+1;
		fa[bn[p].to]=now;
		q=dfs(bn[p].to,now);
		res+=q;
		if(q>mx)
		{
			mx=q;
			mm=bn[p].to;
		}
	}
	if(mm) top[mm]=now;
	return res;
}

inline lca(ll u,ll v)
{
	for(;ft(u)!=ft(v);)
	{
		if(deep[fa[ft(u)]]<deep[fa[ft(v)]]) swap(u,v);
		u=fa[ft(u)];
	}
	return deep[u]>deep[v]?v:u;
}

void df(int now,int last)
{
	int p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(last==bn[p].to) continue;
		df(bn[p].to,now);
		num[now]+=num[bn[p].to];
	}
}

int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	memset(first,-1,sizeof(first));
	ll i,j,p,q,l;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&p,&q);
		add(p,q);
		add(q,p);
		top[i]=i;
	}
	top[n]=n;
	deep[1]=1;
	dfs(1,-1);
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		l=lca(p,q);
		num[p]++,num[q]++;
		num[l]-=2;
	}
	df(1,-1);
	for(i=1;i<=bb;i+=2)
	{
		p=(deep[bn[i].from]<deep[bn[i].to]? bn[i].to:bn[i].from);
		printf("%d ",num[p]);
	}
}