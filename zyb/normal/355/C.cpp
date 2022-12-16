#include<stdio.h>
#include<algorithm>
using namespace std;
int n,l,r,xl,xr,i,j,k,s,m;
int sum[100005],ss[100005],a[100005];
inline int work(int o,int p)
{
	if (abs(o-p)<=1)
	return 0;
	if (o>p)
	return xl*(o-p-1);
	else
	return xr*(p-o-1);
}
int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&xl,&xr);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for (i=n;i;i--)
	ss[i]=ss[i+1]+a[i];
	int ans=1000000000;
	for (i=0;i<=n;i++)
	ans=min(ans,sum[i]*l+ss[i+1]*r+work(i,n-i));
	printf("%d\n",ans);
}