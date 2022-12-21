#include<stdio.h>
using namespace std;
int a[105],i,j,k,l,s,m,n;
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&j);
		a[j]=1;
	}
	for (i=1;i<=l;i++)
	{
		scanf("%d",&j);
		if (!a[j])
		a[j]=2;
	}
	for (i=1;i<=n;i++)
	{
		if (!a[i])
		a[i]=2;
		printf("%d ",a[i]);
	}
}