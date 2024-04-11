#include<stdio.h>
using namespace std;
int a[1005],i,j,k,l,s,m,n,x,y;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y]++;
	}
	for (i=1;i<=n;i++)
	{
		if (!a[i])
		{
			printf("%d\n",n-1);
			for (j=1;j<=n;j++)
			{
				if (i==j)
				continue;
				printf("%d %d\n",i,j);
			}
			return 0;
		}
	}
}