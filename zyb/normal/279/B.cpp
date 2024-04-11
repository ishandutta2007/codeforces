#include<stdio.h>
#include<algorithm>
using namespace std;
int f[100005],a[100005],i,j,k,l,s,m,n,ans;
inline int erfen(int l,int r,int o)
{
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (f[o]-f[mid]<=m)
		r=mid;
		else
		l=mid+1;
	}
	return o-r;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=f[i-1]+a[i];
	}
	for (i=1;i<=n;i++)
	ans=max(ans,erfen(0,i,i));
	printf("%d\n",ans);
}