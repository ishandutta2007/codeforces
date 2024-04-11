#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[310000];
long long ksm(long long x,long long k)
{
	long long s=1;
	while(k>0)
	{
		if(k&1)s=s*x%998244353;
		x=x*x%998244353;
		k>>=1;
	}
	return s;
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n*2;i++)scanf("%d",&a[i]);
	long long s=1,sr=1;
	for(int i=1;i<=n*2;i++)s=s*i%998244353;
	for(int i=1;i<=n;i++)sr=sr*i%998244353;
	s=s*ksm(sr,998244351)%998244353*ksm(sr,998244351)%998244353;
	long long ss=0;
	sort(a+1,a+2*n+1);
	for(int i=1;i<=n;i++)ss=(ss-s*a[i]%998244353+998244353)%998244353;
	for(int i=n+1;i<=n*2;i++)ss=(ss+s*a[i]%998244353+998244353)%998244353;
	printf("%lld\n",ss);
	return 0;
}