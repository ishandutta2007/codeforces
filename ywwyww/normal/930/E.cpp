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
void put(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	static int c[20];
	int t=0;
	while(x)
	{
		c[++t]=x%10;
		x/=10;
	}
	while(t)
		putchar(c[t--]+'0');
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
const ll p=1000000007;
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
int k,n,m;
pii a[400010];
pii b[400010];
pii c[400010];
pii d[400010];
int e[400010];
int t;
ll f0[400010];
ll f1[400010];
ll g[400010];
int l0[400010];
int l1[400010];
int cmp(pii a,pii b)
{
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second>b.second;
}
int main()
{
	open("b");
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].first,&b[i].second);
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp);
	int t1=0,t2=0;
	for(int i=1;i<=n;i++)
	{
		while(t1&&a[i].second<=c[t1].second&&a[i].first>=c[t1].first)
			t1--;
		c[++t1]=a[i];
	}
	n=t1;
	for(int i=1;i<=m;i++)
	{
		while(t2&&b[i].second<=d[t2].second&&b[i].first>=d[t2].first)
			t2--;
		d[++t2]=b[i];
	}
	m=t2;
	sort(c+1,c+n+1);
	sort(d+1,d+m+1);
	t=0;
	for(int i=1;i<=n;i++)
	{
		e[++t]=c[i].first;
		e[++t]=c[i].second+1;
	}
	for(int i=1;i<=m;i++)
	{
		e[++t]=d[i].first;
		e[++t]=d[i].second+1;
	}
	e[++t]=k+1;
	e[++t]=1;
	sort(e+1,e+t+1);
	t=unique(e+1,e+t+1)-e-1;
	for(int i=1;i<=n;i++)
	{
		c[i].first=lower_bound(e+1,e+t+1,c[i].first)-e;
		c[i].second=lower_bound(e+1,e+t+1,c[i].second+1)-e;
	}
	for(int i=1;i<=m;i++)
	{
		d[i].first=lower_bound(e+1,e+t+1,d[i].first)-e;
		d[i].second=lower_bound(e+1,e+t+1,d[i].second+1)-e;
	}
	for(int i=1;i<=n;i++)
		l0[c[i].second]=c[i].first;
	for(int i=1;i<=m;i++)
		l1[d[i].second]=d[i].first;
	
	e[t+1]=k+1;
	g[0]=1;
	int last0=0;
	int last1=0;
	ll s0=0;
	ll s1=0;
	for(int i=1;i<t;i++)
	{
		f1[i-1]=(s0+g[i-1])%p;
		f0[i-1]=(s1+g[i-1])%p;
		g[i]=(s0+s1+g[i-1])*(fp(2,e[i+1]-e[i])-2)%p;
		s0=(s0+f0[i-1])%p;
		s1=(s1+f1[i-1])%p;
		for(;last0<l0[i+1];last0++)
			s0=(s0-f0[last0])%p;
		for(;last1<l1[i+1];last1++)
			s1=(s1-f1[last1])%p;
	}

	ll ans=(g[t-1]+s0+s1)%p;
	ans=(ans+p)%p;
	printf("%I64d\n",ans);
	return 0;
}