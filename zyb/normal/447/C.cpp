#include<stdio.h>
using namespace std;
inline int max(int o,int p)
{
	if (o>p)
	return o;
	else return p;
}
int b[100005],c[100005],a[100005];
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	if (a[i]>a[i-1])
	b[i]=b[i-1]+1;
	else
	b[i]=1;
	for (i=n;i;i--)
	if (a[i]<a[i+1])
	c[i]=c[i+1]+1;
	else
	c[i]=1;
	int ans=0;
	for (i=1;i<=n;i++)
	{
		if (a[i+1]-a[i-1]>=2)
		ans=max(ans,c[i+1]+b[i-1]+1);
		ans=max(ans,c[i+1]+1);
		ans=max(ans,b[i-1]+1);
	}
	printf("%d",ans);
}