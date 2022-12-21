#include<stdio.h>
using namespace std;
int a[10005];
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&j);
		j=j%n;
		if (a[j]==1)
		{
			printf("%d",i);
			return 0;
		}
		a[j]=1;
	}
	printf("-1");
}