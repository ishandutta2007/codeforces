#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
pll a[300010];
int inf=1000000000;
ll calc(pll f,int x)
{
	return f.first*x+f.second;
}
namespace sgt
{
	int ls[10000010];
	int rs[10000010];
	int s[10000010];
	int cnt=0;
	int insert(int p1,int v,int l,int r)
	{
		int p=++cnt;
		ls[p]=ls[p1];
		rs[p]=rs[p1];
		s[p]=s[p1];
		if(!s[p])
		{
			s[p]=v;
			return p;
		}
		int t=s[p];
		if(l==r)
		{
			ll t1=calc(a[t],l);
			ll v1=calc(a[v],l);
			if(v1>t1)
				s[p]=v;
			return p;
		}
		int mid=(l+r)>>1;
		ll t1=calc(a[t],l);
		ll t2=calc(a[t],mid);
		ll t3=calc(a[t],mid+1);
		ll t4=calc(a[t],r);
		ll v1=calc(a[v],l);
		ll v2=calc(a[v],mid);
		ll v3=calc(a[v],mid+1);
		ll v4=calc(a[v],r);
		if(t1>=v1&&t4>=v4)
			return p;
		if(v1>=t1&&v4>=t4)
		{
			s[p]=v;
			return p;
		}
		if(t1>=v1&&t2>=v2)
		{
			rs[p]=insert(rs[p],v,mid+1,r);
			return p;
		}
		if(t3>=v3&&t4>=v4)
		{
			ls[p]=insert(ls[p],v,l,mid);
			return p;
		}
		s[p]=v;
		if(v1>=t1&&v2>=t2)
		{
			rs[p]=insert(rs[p],t,mid+1,r);
			return p;
		}
		if(v3>=t3&&v4>=t4)
		{
			ls[p]=insert(ls[p],t,l,mid);
			return p;
		}
		int orzzjt=1;
		return p;
	}
	ll query(int p,int v,int l,int r)
	{
		if(!s[p])
			return 0x8000000000000000ll;
		int t=s[p];
		ll s=calc(a[t],v);
		if(l==r)
			return s;
		int mid=(l+r)>>1;
		if(v<=mid)
			s=max(s,query(ls[p],v,l,mid));
		else
			s=max(s,query(rs[p],v,mid+1,r));
		return s;
	}
}
namespace list
{
	int v[10000000];
	int t[10000000];
	int h[1000010];
	int n;
	void init()
	{
		n=0;
		memset(h,0,sizeof h);
	}
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
}
int del[300010];
int op[300010];
int qv[300010];
int qs[300010];
pii c[600010];
int ls[600010];
int rs[600010];
int cnt;
ll ans[300010];
void solve(int p,int l,int r,int fr)
{
	if(!(qs[r]-qs[l-1]))
		return;
	int rt=fr;
	int t=sgt::cnt;
	int i;
	if(l!=r)
	{
		ls[p]=++cnt;
		rs[p]=++cnt;
	}
	int mid=(l+r)>>1;
	for(i=list::h[p];i;i=list::t[i])
		if(c[list::v[i]].first<=l&&c[list::v[i]].second>=r)
			rt=sgt::insert(rt,list::v[i],-inf,inf);
		else
		{
			if(c[list::v[i]].first<=mid)
				list::add(ls[p],list::v[i]);
			if(c[list::v[i]].second>mid)
				list::add(rs[p],list::v[i]);
		}
	if(l==r)
		ans[l]=sgt::query(rt,qv[l],-inf,inf);
	else
	{
		solve(ls[p],l,mid,rt);
		solve(rs[p],mid+1,r,rt);
	}
	sgt::cnt=t;
}
int main()
{
	list::init();
	open("c");
	int n;
	scanf("%d",&n);
	int i,x;
	int now=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			scanf("%I64d%I64d",&a[i].first,&a[i].second);
			now++;
		}
		else if(op[i]==2)
		{
			scanf("%d",&x);
			del[x]=i;
			now--;
		}
		else
		{
			scanf("%d",&qv[i]);
			if(!now)
				ans[i]=0x7fffffffffffffffll;
			else
				qs[i]=1;
		}
		qs[i]+=qs[i-1];
	}
	cnt=1;
	for(i=1;i<=n;i++)
		if(op[i]==1)
		{
			if(!del[i])
				c[i]=pii(i,n);
			else
				c[i]=pii(i,del[i]-1);
			list::add(1,i);
		}
	solve(cnt,1,n,0);
	for(i=1;i<=n;i++)
		if(op[i]==3)
		{
			if(ans[i]==0x7fffffffffffffffll)
				printf("EMPTY SET\n");
			else
				printf("%I64d\n",ans[i]);
		}
	return 0;
}