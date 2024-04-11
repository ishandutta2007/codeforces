#include<cstdio>
#include<cstring>
using namespace std;
long long n;
long long p(long long x)
{
	long long s=0,g=1;
	while(x<=n)
	{
		if(x+g<=n)s+=g;
		else s+=n-x+1;
		g<<=1;
		x<<=1;
	}
	return s;
}
int main()
{
	long long k;scanf("%lld%lld",&n,&k);
	long long l=1,r=(n+1)/2;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(p(mid*2-1)>=k)l=mid;
		else r=mid-1;
	}
	long long ss=l*2-1;
	l=0;r=n/2;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(p(mid)-1>=k)l=mid;
		else r=mid-1;
	}
	if(l*2>ss)ss=l*2;
	printf("%lld\n",ss);
	return 0;
}