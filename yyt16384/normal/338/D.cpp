#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXK=10005;
long long n,m;
int k;
long long a[MAXK];
long long ll;
long long rr;
void init()
{
	scanf(LLFORMAT"d"LLFORMAT"d%d",&n,&m,&k);
	for (int i=0;i<k;++i)
		scanf(LLFORMAT"d",&a[i]);
}
long long gcd(long long x,long long y)
{
	long long z;
	while (y) z=x%y,x=y,y=z;
	return x;
}
void ext_euc(long long a,long long b,long long &x,long long &y)
{
	if (b==0)
	{
		x=1;y=0;
		return;
	}
	ext_euc(b,a%b,y,x);
	y-=a/b*x;
}
long long inv(long long a,long long b)
{
	long long x,y;
	ext_euc(a,b,x,y);
	return (x%b+b)%b;
}
long long multmod(long long x,long long y,long long z)
{
	long long s=0;
	while (y)
	{
		if (y&1) s=(s+x)%z;
		x=(x+x)%z;
		y>>=1;
	}
	return s;
}
void solve()
{
	ll=1;rr=0;
	for (int i=0;i<k;++i)
	{
		long long d=gcd(ll,a[i]);
		if ((long double)(ll/d)*a[i]>1e13 || ll/d*a[i]>n)
		{
			printf("NO\n");
			return;
		}
		long long u=((-i-rr)%a[i]+a[i])%a[i];
		if (u%d)
		{
			printf("NO\n");
			return;
		}
		u/=d;
		long long p=ll/d,q=a[i]/d;
		long long x=multmod(u,inv(p%q,q),q);
		rr+=x*ll;
		if (rr+k-1>m)
		{
			printf("NO\n");
			return;
		}
		ll=ll/d*a[i];
	}
	if (rr==0) rr+=ll;
	if (rr+k-1>m)
	{
		printf("NO\n");
		return;
	}
	for (int i=0;i<k;++i)
		if (gcd(ll,rr+i)!=a[i])
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8751.in","r",stdin);
	freopen("8751.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}