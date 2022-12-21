#include<stdio.h>
using namespace std;
int a[100005],b[100005],i,j,s,s1;
long long n,m,ans;
int bb=0;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	int s=0,s1=0;
	while (n)
	{
		a[++s]=n%2;
		n/=2;
	}
	while (m)
	{
		b[++s1]=m%2;
		m/=2;
	}
	for (i=s1;i;i--)
	{
		if (bb)
		ans=ans*2+1;
		else
		if (a[i]!=b[i])
		{	
			ans=ans*2+1;
			bb=1;
		}
	}
	printf("%I64d\n",ans);
}