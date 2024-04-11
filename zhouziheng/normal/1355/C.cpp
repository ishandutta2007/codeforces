#include<cstdio>

using namespace std;

long long x[2000000];const int N=1e6;

int main()
{
	long long a=0,b=0,c=0,d=0;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(int i=a;i<=b;i++)
	{
		x[i+b]++,x[i+c+1]--;
	}
	for(int i=1;i<=N;i++)x[i]+=x[i-1];
	for(int i=N-1;i>=0;i--)x[i]+=x[i+1];
	long long ans=0;
	for(int i=c;i<=d;i++)ans+=x[i+1];
	printf("%lld",ans);return 0;
}