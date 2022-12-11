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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main()
{
	ll n,a,b;
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	ll x,y,d;
	d=exgcd(a,b,x,y);
	if(n%d!=0)
		printf("NO\n");
	else
	{
		x*=n/d;
		y*=n/d;
		while(y<0)
		{
			x-=b/d;
			y+=a/d;
		}
		while(x<0)
		{
			x+=b/d;
			y-=a/d;
		}
		if(y>=0)
			printf("YES\n%I64d %I64d\n",x,y);
		else
			printf("NO\n");
	}
	return 0;
}