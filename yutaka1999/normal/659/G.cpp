#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll A[SIZE];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	ll ret=0;
	ll a=0,b=0,c=0,d=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			a=A[i]-1;
			b=1;
			c=0;
			d=0;
		}
		else if(A[i-1]<A[i])
		{
			ll na=A[i-1]-1;
			ll nb=(a*b+c*d)%MOD;
			ll nc=A[i]-1;
			ll nd=1;
			a=na,b=nb,c=nc,d=nd;
		}
		else
		{
			ll na=A[i]-1;
			ll nb=(min(a,A[i]-1)*b+min(c,A[i]-1)*d+1)%MOD;
			a=na,b=nb,c=0,d=0;
		}
		ret+=(a*b+c*d)%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	printf("%lld\n",ret);
	return 0;
}