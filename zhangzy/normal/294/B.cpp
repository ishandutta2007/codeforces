#include<cstdio>
#include<iostream>
#include<algorithm>
#define xx 110
using namespace std;
int a[xx],ga=0,sa[xx],b[xx],gb=0,sb[xx],n,x,y,ans=10000;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&x,&y);
		if (x==1) a[++ga]=y;
		if (x==2) b[++gb]=y;
	}
	sort(a+1,a+ga+1);
	sort(b+1,b+gb+1);
	sa[0]=0;sb[0]=0;
	for (int i=1;i<=ga;i++)
		sa[i]=sa[i-1]+a[i];
	for (int i=1;i<=gb;i++)
		sb[i]=sb[i-1]+b[i];
	for (int i=0;i<=ga;i++)
		for (int j=0;j<=gb;j++)
			if (sa[i]+sb[j]<=(ga-i+2*(gb-j)))
				ans=min(ga-i+2*(gb-j),ans);
	printf("%d",ans);
}