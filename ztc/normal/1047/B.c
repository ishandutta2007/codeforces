#include<stdio.h>
int n,a,b,maxx=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a+b>maxx)maxx=a+b;
	}printf("%d",maxx);
}