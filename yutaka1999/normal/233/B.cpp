#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int ll;

ll n;
ll sum(ll x)
{
	ll sum=0;
	for(ll s=1;s<=x;s*=10) sum+=x/s-(x/(s*10))*10;
	return sum;
}
bool ok(ll x,int i)
{
	return sum(x)==i&&x*(x+i)==n;
}
double fir[3];
ll ans[5];
void test(int x)
{
	double d=x*x+4*n;
	fir[0]=(-x+sqrt(d))/2;
	fir[1]=(-x-sqrt(d))/2;
	ans[0]=floor(fir[0]);
	ans[1]=ceil(fir[0]);
	ans[2]=floor(fir[1]);
	ans[3]=ceil(fir[1]);
}

int main()
{
	scanf("%I64d",&n);
	for(int i=0;i<100;i++)
	{
		test(i);
		for(int j=0;j<4;j++)
		{
			if(ans[j]>0&&ok(ans[j],i))
			{
				printf("%I64d\n",ans[j]);
				return 0;
			}
		}
	}
	printf("%d\n",-1);
	return 0;
}