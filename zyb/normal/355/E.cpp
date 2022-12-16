#include<stdio.h>
#include<algorithm>
using namespace std;
int sum[1000005],i,j,k,l,s,m,n;
int a[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	int ma=0,mi=10000000;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		a[j]++;
		mi=min(mi,j);
		ma=max(ma,j);
	}
	for (i=1;i<=ma;i++)
	sum[i]=sum[i-1]+a[i];
	for (i=mi;i;i--)
	{
		s=0;
		for (j=1;j*i<=ma;j++)
		s=s+(sum[min(ma,min(i*j+m,i*(j+1)-1))]-sum[i*j-1]);
		if (s==n)
		{
			printf("%d",i);
			return 0;
		}
	}
}