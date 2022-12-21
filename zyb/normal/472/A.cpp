#include<stdio.h>
using namespace std;
int f[1000005];
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d",&n);
	for (i=2;i<=n;i++)
	{
		if (!f[i])
		{
			f[i]=1;
			for (j=2;j*i<=n;j++)
			f[j*i]=2;
		}
	}
	for (i=1;i<=n;i++)
	if (f[i]==2&&f[n-i]==2)
	{
		printf("%d %d",i,n-i);
		return 0;
	}
}