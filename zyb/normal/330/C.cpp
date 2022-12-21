#include<stdio.h>
using namespace std;
int a[105][105],b[105],c[105];
char cc;
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		cc=getchar();
		while (cc!='.'&&cc!='E')
		cc=getchar();
		if (cc=='.')
		{
			a[i][j]=1;
			b[i]++;c[j]++;
		}
		else
		a[i][j]=0;
	}
	bool bb=true,b1=true;
	for (i=1;i<=n;i++)
	if (!b[i])
	bb=0;
	for (j=1;j<=n;j++)
	if (!c[j])
	{
		b1=0;
	}
	if (!bb&&!b1)
	{
		printf("-1");
		return 0;
	}
	if (bb)
	{	
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			if (a[i][j])
			{
				printf("%d %d\n",i,j);
				break;
			}
		}
	}
	else
	{	
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			if (a[j][i])
			{
				printf("%d %d\n",j,i);
				break;
			}
		}
	}
}