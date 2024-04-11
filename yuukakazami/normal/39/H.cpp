#include<cstdio>

int n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<n;j++)
			if (i*j>=n)
				printf("%d%d ",i*j/n,i*j%n);
			else
				printf("%d ",i*j%n);
		printf("\n");
	}
	return 0;
}