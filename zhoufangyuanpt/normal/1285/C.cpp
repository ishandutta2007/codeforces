//luogu
#include<cstdio>
#include<cstring>
using namespace std;
long long a[110];
int main()
{
	long long n;scanf("%lld",&n);
	long long nn=n;
	int len=0;
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a[++len]=1;
			while(n%i==0)n/=i,a[len]*=i;
		}
	}
	if(n>1)a[++len]=n;
	long long ss=nn;
	for(int i=0;i<1<<len;i++)
	{
		long long s=1;
		for(int j=0;j<len;j++)
		{
			if(i&1<<j)
			{
				s=s*a[j+1];
			}
		}
		if(s<nn/s)s=nn/s;
		if(s<ss)ss=s;
	}
	printf("%lld %lld\n",nn/ss,ss);
	return 0;
}