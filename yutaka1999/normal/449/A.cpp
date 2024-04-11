#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define LM 100000

using namespace std;
typedef long long int ll;

int main()
{
	ll n,m,k;
	scanf("%I64d %I64d %I64d",&n,&m,&k);
	if((n-1)+(m-1)<k)
	{
		puts("-1");
	}
	else
	{
		ll ret=0;
		for(int i=1;i<=LM;i++)
		{
			if(i>n||i-1>k||k-i+2>m) continue;
			ll a=n/i;
			ll b=m/(k-i+2);
			ret=max(ret,a*b);
		}
		for(int i=1;i<=LM;i++)
		{
			if(i>n) continue;
			ll cnt=n/i;
			cnt=min(cnt,k+1);
			if(n/cnt!=i||cnt-1>k) continue;
			ll a=m/(k-(cnt-1)+1);
			ret=max(ret,a*(ll) i);
		}
		printf("%I64d\n",ret);
	}
	return 0;
}