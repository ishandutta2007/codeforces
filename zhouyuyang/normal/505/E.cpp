#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long g[120000],h[120000],l[120000];
int i,k,m,n,p;
long long r,s,t,u,v,ll,rr,mid;

inline bool check(long long x)
{
	s=0;
	for (i=1;i<=n;i++)
		if (h[i]>x)
			s=s+(h[i]-x+p-1)/p;
	if (s>m*k)
		return false;
	memset(g,0,sizeof(g));
	for (i=1;i<=n;i++)
	{
		if (h[i]<=x)
			continue;
		t=(h[i]-x+p-1)/p,u=x,v=m+1;
		while (t>0)
		{
			r=u/l[i];
			v=v-r;
			if (v<=0)
				v=1;
			if (v==m+1)
				return false;
			g[v]++;
			t--;
			u=u-l[i]*r+p;
		}
	}
	s=0;
	for (i=m;i>0;i--)
	{
		s=s+g[i];
		if (s>(m-i+1)*k)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&h[i],&l[i]);
		h[i]=1LL*l[i]*m+h[i],rr=max(rr,h[i]);
	}
	ll=0;
	while (ll<rr)
	{
		mid=(ll+rr)/2;
		if (check(mid))
			rr=mid;
		else
			ll=mid+1;
	}
	printf("%I64d",ll);
	return 0;
}