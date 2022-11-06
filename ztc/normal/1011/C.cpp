#include<bits/stdc++.h>
using namespace std;
int n,i;
double r,a[1002],b[1002],w;
int main()
{
	scanf("%d%lf",&n,&w);
	r=w;
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		if(a[i]<=1)
		{
			printf("-1");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&b[i]);
		if(b[i]<=1)
		{
			printf("-1");
			return 0;
		}
	}
	r=r/(b[1]-1)*b[1]/(a[n]-1)*a[n];
	for(i=n;i>=2;i--)r=r/(b[i]-1)*b[i]/(a[i-1]-1)*a[i-1];
	printf("%.10lf",r-w);
}