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
int f[200010][20];
int mx[200010][20];
int d[200010];
list<pii> l[200010];
void dfs(int x,int fa,int dep,int from)
{
	f[x][0]=fa;
	d[x]=dep;
	mx[x][0]=from;
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
int query(int x,int y)
{
	int s=0;
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
struct p
{
	int x,y;
	int b;
	int id;
	int d;
	p()
	{
		b=0;
	}
};
p a[200010];
int cmp(p a,p b)
{
	return a.d<b.d;
}
struct uni
{
	int f[200010];
	int find(int x)
	{
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void merge(int x,int y)
	{
		f[find(x)]=find(y);
	}
};
uni c;
void add(int x,int y,int z)
{
	l[x].push_back(pii(y,z));
	l[y].push_back(pii(x,z));
}
ll ans[200010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].d);
		a[i].id=i;
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=n;i++)
		c.f[i]=i;
	ll sum=0;
	for(i=1;i<=m;i++)
		if(c.find(a[i].x)!=c.find(a[i].y))
		{
			c.merge(a[i].x,a[i].y);
			sum+=a[i].d;
			add(a[i].x,a[i].y,a[i].d);
			a[i].b=1;
		}
	dfs(1,0,1,0);
	for(i=1;i<=m;i++)
		if(a[i].b)
			ans[a[i].id]=sum;
		else
			ans[a[i].id]=sum+a[i].d-query(a[i].x,a[i].y);
	for(i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
	return 0;
}