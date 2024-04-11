#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef long long int ll;

ll n,c;
ll x1,y1,x2,y2;

ll two(ll x)
{
	if(x<0) return 0;
	return x*(x+1)/2;
}
ll ryo(ll x,ll y,ll t)
{
	if(x>=t&&y>=t) return two(t);
	if(x+y-1<=t) return x*y;
	return two(t)-two(t-y)-two(t-x);
	/*
	|--------|
	|..      |        x=7
	|...     | -----> y=4 -----> ryo(x,y,t) = 14
	|....    |        t=5
	|.....   |
	|--------|
	*/
}
bool ok(ll t)
{
	ll all=1;
	all+=ryo(x1,y1,t);
	all+=ryo(x1,y2,t);
	all+=ryo(x2,y1,t);
	all+=ryo(x2,y2,t);
	all-=min(t,x1);
	all-=min(t,y1);
	all-=min(t,x2);
	all-=min(t,y2);
	return all>=c;
}
int main()
{
	scanf("%I64d %I64d %I64d %I64d",&n,&x1,&y1,&c);
	x2=n-x1+1,y2=n-y1+1;
	ll s=0,e=n*n;
	while(e-s>1)
	{
		ll med=(s+e)/2;
		if(ok(med)) e=med;
		else s=med;
	}
	printf("%I64d\n",e-1);
	return 0;
}