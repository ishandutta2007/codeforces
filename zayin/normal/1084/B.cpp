#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
typedef long long LL;

int n;
LL s,sum,a[maxn];

bool judge(LL d)
{
	LL t=0;
	for (int i=0;i<n;++i)
		if (a[i]<d)
			return 0;
		else
			t+=a[i]-d;
	return t>=s;
}

int main()
{
	scanf("%d%lld",&n,&s);
	for (int i=0;i<n;++i)
		scanf("%lld",a+i),sum+=a[i];
	
	if (sum<s)	return puts("-1"),0;

	LL l=0,r=sum;
	while (l<r)
	{
		LL mid=(l+r+1)>>1;
		if (judge(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}