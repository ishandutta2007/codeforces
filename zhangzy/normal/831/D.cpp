#include<cstdio>
#include<iostream>
#include<algorithm>
#define xxx 2020
#define ll long long
using namespace std;
ll n,m,o,a[xxx],b[xxx],ans;

ll abss(ll x)
{
	return x>0? x:-x;
}

bool pd(ll d)
{
	int p=0;
	for (int i=1;i<=n;i++)
	{
		p++;
		while ( ( abss(a[i]-b[p])+abss(b[p]-o) )>d&&p<=m ) p++;
		if (p>m) return 0;
	}
	return 1;
}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&o);
	for (int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	ll l=0,r=2000000000,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (pd(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%I64d",ans);
}