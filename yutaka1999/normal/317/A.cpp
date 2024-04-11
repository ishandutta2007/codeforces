#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	ll x,y,m;
	scanf("%I64D %I64d %I64d",&x,&y,&m);
	if(x>y) swap(x,y);
	if(m<=y)
	{
		puts("0");
		return 0;
	}
	if(y<=0)
	{
		puts("-1");
		return 0;
	}
	ll ret=0;
	if(x<0)
	{
		ll pl=(llabs(x)+y-1)/y;
		ret+=pl;
		x+=pl*y;
	}
	while(y<m)
	{
		ret++;
		ll nx=y,ny=x+y;
		x=nx;y=ny;
	}
	printf("%I64d\n",ret);
	return 0;
}