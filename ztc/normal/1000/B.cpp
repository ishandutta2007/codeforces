#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cmath>
#define inf 1000000007
using namespace std;
int a[100002],n,m,cnt=-1,maxx=0,ans=0,i;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i-1]=a[i]-a[i-1];
	}
	a[n]=m-a[n];
	for(i=0;i<=n;i+=2)
	{
		ans+=a[i];
	}
	if(n&1)
	{
		for(i=n;i>=1;i-=2)
		{
			cnt=cnt+a[i]-a[i+1];
			maxx=max(maxx,cnt);
		}
	}
	else
	{
		for(i=n;i>=2;i-=2)
		{
			cnt=cnt+a[i-1]-a[i];
			maxx=max(maxx,cnt);
		}
	}
	printf("%d",ans+maxx);
}