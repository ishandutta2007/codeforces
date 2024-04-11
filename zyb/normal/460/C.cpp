#include<stdio.h>
#include<cstring>
#define lowbit(o) o&(-o)
#include<algorithm>
using namespace std;
long long f[100005],a[100005];
long long i,j,k,l,s,m,n,w;
inline void add(long long o,long long p)
{
	for (;o;o-=lowbit(o))
	f[o]+=p;
}
inline long long ask(long long o)
{
	long long ans=0;
	for (;o<=n;o+=lowbit(o))
	ans+=f[o];
	return ans;
}
inline bool check(long long o)
{
	long long s=0;
	memset(f,0,sizeof(f));
	for (long long i=1;i<=n;i++)
	{
		long long yy=ask(i);
		if (a[i]+yy<=o)
		{
			s=s+(o-a[i]-yy);
			add(i-1,-(o-a[i]-yy));
			add(min(i+w-1,n),(o-a[i]-yy));
		}
	}
	if (s<=m)
	return true;
	else
	return false;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&w);
	for (i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	long long l=0,r=2000000000;
	long long ans=0;
	while (l<=r)
	{
		long long mid=(l+r)>>1;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		r=mid-1;
	}
	printf("%I64d\n",ans);
}