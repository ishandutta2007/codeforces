#include<stdio.h>
using namespace std;
int i,j,k,l,s,m,n;
int q[100005],b[100005],a[100005],aa[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	scanf("%d",&q[i]);
	for (i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for (i=1;i<=n;i++)
	a[i]=aa[i]=i;
	int j=0;
	while (j<=m)
	{
		for (i=1;i<=n;i++)
		if (a[i]!=b[i])
		break;
		if (i>n)
		break;
		for (i=1;i<=n;i++)
		aa[i]=a[q[i]];
		for (i=1;i<=n;i++)
		a[i]=aa[i];
		j++;
	}
	for (i=1;i<=n;i++)
	a[i]=aa[i]=i;
	int jj=0;
	while (jj<=m)
	{
		for (i=1;i<=n;i++)
		if (a[i]!=b[i])
		break;
		if (i>n)
		break;
		for (i=1;i<=n;i++)
		aa[q[i]]=a[i];
		for (i=1;i<=n;i++)
		a[i]=aa[i];
		jj++;
	}
	if (j==1&&jj==1&&m!=1)
	{
		printf("NO");
		return 0;
	}
	if (j>m&&jj>m)
	{
		printf("NO");
		return 0;
	}
	if (j==0||jj==0)
	{
		printf("NO");
		return 0;
	}
	if ((m-j)%2==0)
	{
		printf("YES");
		return 0;
	}
	if ((m-jj)%2==0)
	{
		printf("YES");
		return 0;
	}
	printf("NO");
	
}