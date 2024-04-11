#include<stdio.h>
using namespace std;
int i,j,k,l,s,m,n,x,y;
int a[100005],f[100005];;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=f[i-1]+a[i];
	}
	int s=f[n];
	scanf("%d%d",&x,&y);
	for (i=1;i<=n;i++)
	if (f[i-1]>=x&&f[i-1]<=y)
	if (s-f[i-1]>=x&&s-f[i-1]<=y)
	{
		printf("%d\n",i);
		return 0;
	}
	printf("0");
}