#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
int n,m;
int d[2000010];
int st[2000010];
int ed[2000010];
int ti;
ll c[2][2000010];
ll a[2000010];
list<int> l[2000010];
void dfs(int x,int f,int dep)
{
	d[x]=dep;
	st[x]=++ti;
	for(auto v:l[x])
		if(v!=f)
			dfs(v,x,dep+1);
	ed[x]=ti;
}
void add(ll *c,int x,ll v)
{
	for(;x<=n;x+=x&-x)
		c[x]+=v;
}
ll sum(ll *c,int x)
{
	ll s=0;
	for(;x;x-=x&-x)
		s+=c[x];
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof a);
	memset(c,0,sizeof c);
	int x,y,i;
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		l[x].push_back(y);
		l[y].push_back(x);
	}
	ti=0;
	dfs(1,0,1);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d%d",&x,&y);
			add(c[d[x]&1],st[x],y);
			add(c[d[x]&1],ed[x]+1,-y);
			add(c[(d[x]&1)^1],st[x],-y);
			add(c[(d[x]&1)^1],ed[x]+1,y);
		}
		else
		{
			scanf("%d",&x);
			ll s=a[x];
			s+=sum(c[d[x]&1],st[x]);
			printf("%I64d\n",s);
		}
	}
	return 0;
}