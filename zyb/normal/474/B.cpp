#include<stdio.h>
using namespace std;
int i,j,k,m,n,ans;
int a[100005],s[100005];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&j);
		int l=1,r=n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (s[mid]>=j)
			{
				ans=mid;
				r=mid-1;
			}
			else
			l=mid+1;
		}
		printf("%d\n",ans);
	}
}