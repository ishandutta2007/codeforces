#include<stdio.h>
using namespace std;
long long n,m,k;
inline long long min(long long o,long long p)
{
	if (o<p)
	return o;
	else return p;
}
inline bool check(long long o)
{
	long long s=0;
	for (long long i=1;i<=n;i++)
	s=s+min(o/i,m);
	if (s>=k)
	return true;
	else
	return false;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	long long l=0,r=1ll*n*m;
	while (l<r)
	{
		long long mid=(l+r)>>1;
		if (check(mid))
		r=mid;
		else
		l=mid+1;
	}
	printf("%I64d\n",r);
}