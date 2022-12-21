#include<stdio.h>
using namespace std;
int i,j,k,l,s,m,n;
int a[35],b[35];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		scanf("%d",&k);
		a[i]+=k;
		b[j]+=k;
	}
	int ans=0;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	if (b[j]>a[i])
	ans++;
	printf("%d\n",ans);
}