#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1000500
using namespace std;
typedef long long LL;

int Q;

int n;
LL x,a[maxn];

LL sum[maxn],h[maxn];

double ans;

int main()
{
//	freopen("c.in","r",stdin);
	int opt;
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d",&opt);
		if (opt==1)
		{
			scanf("%I64d",&x);
			
			a[++n]=x;
			sum[n]=sum[n-1]+a[n];
			h[n]=n*a[n]-sum[n-1];
			
			int l=1,r=n;
			while (l<r)
			{
				int mid=(l+r)>>1;
				if (h[mid]<x)
					l=mid+1;
				else
					r=mid;
			}
			
			ans=max(ans,(double)x-(double)(x+sum[l-1])/(double)l);
//			cout<<h[n]<<" "<<l<<" "<<ans<<endl;
		} else printf("%.10lf\n",ans);
	}
	return 0;
}