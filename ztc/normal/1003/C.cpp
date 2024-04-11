#include<stdio.h>
#include<iostream>
#include<deque>
using namespace std;
int n,i,j,b,x,k;
double ans=0,a[5002];
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		a[i]+=a[i-1];
	}
	for(i=0;i<=n-k;i++)
	{
		for(j=i+k;j<=n;j++)
		{
			if((a[j]-a[i])/(j-i)>ans)ans=(a[j]-a[i])/(j-i);
		}
	}
	printf("%lf",ans);
	return 0;
}