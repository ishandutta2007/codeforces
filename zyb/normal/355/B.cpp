#include<stdio.h>
#include<algorithm>
using namespace std;
int ans,i,j,k,l,s,m,n,x1,x2,x3,x4;
int a[100005];
int main()
{
	scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	ans=0;
	s=0;
	for (i=1;i<=n;i++)
	{
		if (a[i]*x1<x2)
		s=s+a[i]*x1;
		else
		s=s+x2;
	}
	s=min(s,x3);
	ans+=s;
	s=0;
	for (i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]*x1<x2)
		s=s+a[i]*x1;
		else
		s=s+x2;
	}
	s=min(s,x3);
	ans+=s;
	ans=min(ans,x4);
	printf("%d\n",ans);
}