#include<stdio.h>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int a[1002],b[1002];
int t,m,n,f[1002],i,j,l,r,h,cnt=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt^=a[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		cnt^=b[i];
	}
	if(cnt)
	{
		printf("NO");
		return 0;
	}
	else
	{
		printf("YES\n");
		cnt=0;
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=m-1;j++)printf("0 ");
			printf("%d\n",a[i]);
		}
		for(i=1;i<=m-1;i++)
		{
			printf("%d ",b[i]);
			cnt^=b[i];
		}
		printf("%d",a[n]^cnt);
	}
	return 0;
}