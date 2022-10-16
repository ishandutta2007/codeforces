#include<cstdio>
#include<algorithm>

using namespace std;

int n=0;long long a=0,r=0,m=0;
long long h[300000],t[300000];

long long f(long long x)
{
	for(int i=1;i<=n;i++)t[i]=h[i]-x;
	
	long long ans=0;
	if(a+r<=m)
	{
		for(int i=1;i<=n;i++)ans=ans+(t[i]<0?-t[i]*a:t[i]*r);return ans;
	}
	long long s1=0,s2=0;for(int i=1;i<=n;i++)if(t[i]>0)s1+=t[i];else s2+=-t[i];
	return min(s1,s2)*m+(s1-min(s1,s2))*r+(s2-min(s1,s2))*a;
}

int main()
{
	scanf("%d%lld%lld%lld",&n,&a,&r,&m);for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	long long l=0,r=1e9;
	while(l<r-1)
	{
		int mid=(l+r)>>1,mmid=(mid+r)>>1;
		if(f(mid)<f(mmid))r=mmid;else l=mid;
	}
	printf("%lld",min(f(l),f(r)));
	return 0;
}