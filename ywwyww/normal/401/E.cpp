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
struct graph
{
	int v[2000010];
	int t[2000010];
	int h[100010];
	int n;
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
};
graph g;
int n,m;
int l,r;
ll p;
int pri[100010];
int b[100010];
int miu[100010];
int cnt;
ll solve(int x,double b)
{
	ll s=0;
	int i,j;
	for(i=1;i<=x-1&&i<=n;i++)
	{
		ll y=sqrt(ll(x)*x-ll(i)*i-b);
		y=min(y,ll(m));
		ll z=0;
		for(j=g.h[i];j;j=g.t[j])
			if(g.v[j]<=y)
			{
				ll k=g.v[j];
				z=(z+miu[k]*(m*(y/k)+(y/k)-(k*(y/k)+k*(y/k)%p*(y/k))/2))%p;
			}
		(s+=z*(n-i+1))%=p;
	}
	return s;
}
int main()
{
	open("bzoj3701");
	scanf("%d%d%d%d%lld",&n,&m,&l,&r,&p);
	int i,j;
	miu[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!b[i])
		{
			pri[++cnt]=i;
			miu[i]=-1;
		}
		for(j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			b[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				miu[i*pri[j]]=0;
				break;
			}
			miu[i*pri[j]]=-miu[i];
		}
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			g.add(j,i);
	ll ans=solve(r,0)-solve(l,0.5);
	ans=(ans*2%p+p)%p;
	if(l==1)
		ans=(ans+m*ll(n+1)+n*ll(m+1))%p;
	printf("%I64d\n",ans);
	return 0;
}