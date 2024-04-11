#include<stdio.h>
using namespace std;
int a[100005];
int i,j,k,l,s,m,n;
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	{
		int l=i+1,r=n;
		s=0;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (a[mid]-a[i]<=m)
			{
				s=mid;
				l=mid+1;
			}
			else
			r=mid-1;
		}
		if (s==0)
		continue;
		int yy=s-i;
		ans=ans+1ll*(1ll*(yy-1)*(yy)/2);
	}
	printf("%I64d\n",ans);
}