#include<stdio.h>
using namespace std;
int a[20],b[20];
int t,ans,i,j,k,l,s,m,n;
int main()
{
	scanf("%d%d",&n,&m);
	char c;
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	{
		c=getchar();
		while (c!='.'&&c!='S')
		c=getchar();
		if (c=='S')
		a[i]=b[j]=1;
	}
	for (i=1;i<=n;i++)
	if (!a[i])
	{
		ans+=m;
		t++;
	}
	for (i=1;i<=m;i++)
	if (!b[i])
	{
		ans=ans+n-t;
	}
	printf("%d\n",ans);
}