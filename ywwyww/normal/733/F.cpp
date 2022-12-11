#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct uni
{
	int f[500010];
	int find(int x)
	{
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void merge(int x,int y)
	{
		f[find(x)]=find(y);
	}
};
uni b;
int f[500010][20];
pii mx[500010][20];
int d[500010];
struct p
{
	int x,y,w,c;
	int b;
	int id;
	p()
	{
		b=0;
	}
};
int cmp(p a,p b)
{
	return a.w<b.w;
}
p a[500010];
list<pii> l[500010];
void add(int x,int y,int z)
{
	l[x].push_back(pii(y,z));
	l[y].push_back(pii(x,z));
}
void dfs(int x,int fa,int dep,int from)
{
	f[x][0]=fa;
	mx[x][0]=pii(from,x);
	d[x]=dep;
	int i;
	for(i=1;i<=19;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		mx[x][i]=max(mx[x][i-1],mx[f[x][i-1]][i-1]);
	}
	for(auto v:l[x])
		if(v.first!=fa)
			dfs(v.first,x,dep+1,v.second);
}
pii query(int x,int y)
{
	pii s;
	int i;
	if(d[x]<d[y])
		swap(x,y);
	for(i=19;i>=0;i--)
		if(d[f[x][i]]>=d[y])
		{
			s=max(s,mx[x][i]);
			x=f[x][i];
		}
	if(x==y)
		return s;
	for(i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			s=max(s,max(mx[x][i],mx[y][i]));
			x=f[x][i];
			y=f[y][i];
		}
	s=max(s,max(mx[x][0],mx[y][0]));
	return s;
}
int ans2[500010];
int cost[500010];
int we[500010];
int lx[500010];
int ly[500010];
int main()
{
//	freopen("cf733f.in","r",stdin);
//	freopen("cf733f.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i].w);
		we[i]=a[i].w;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i].c);
		cost[i]=a[i].c;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
		lx[i]=a[i].x;
		ly[i]=a[i].y;
	}
	sort(a+1,a+m+1,cmp);
	int t;
	ll s;
	scanf("%d",&t);
	for(i=1;i<=n;i++)
		b.f[i]=i;
	ll ans=0x7fffffffffffffff;
	ll sum=0;
	int k=0;
	int choose;
	memset(ans2,0,sizeof ans2);
	for(i=1;i<=m;i++)
	{
		if(b.find(a[i].x)!=b.find(a[i].y))
		{
			b.merge(a[i].x,a[i].y);
			sum+=a[i].w;
			add(a[i].x,a[i].y,a[i].w);
//			add(a[i].y,a[i].x,a[i].w);
			a[i].b=1;
			ans2[a[i].id]=1;
		}
	}
	dfs(1,0,1,0);
	for(i=1;i<=m;i++)
		if(a[i].b)
		{
			s=sum-t/a[i].c;
			if(s<ans)
			{
				ans=s;
				k=0;
				choose=i;
			}
		}
		else
		{
			pii pp=query(a[i].x,a[i].y);
			s=sum-pp.first+a[i].w-t/a[i].c;
			if(s<ans)
			{
				ans=s;
				k=pp.second;
				choose=i;
			}
		}
	ans2[a[choose].id]=1;
	if(k)
	{
		for(i=1;i<=m;i++)
			if(a[i].b&&((a[i].x==k&&a[i].y==f[k][0])||(a[i].x==f[k][0]&&a[i].y==k)))
			{
				ans2[a[i].id]=0;
				break;
			}
	}
	printf("%I64d\n",ans);
	for(i=1;i<=m;i++)
		if(ans2[i])
		{
			if(i==a[choose].id)
				we[i]-=t/cost[i];
			printf("%d %d\n",i,we[i]);
		}
//	for(i=1;i<=n;i++)
//		b.f[i]=i;
//	for(i=1;i<=m;i++)
//		if(ans2[i])
//		{
//			if(b.find(lx[i])==b.find(ly[i]))
//				printf("%d %d %d\n",i,lx[i],ly[i]);
//			b.merge(lx[i],ly[i]);
//		}
	return 0;
}