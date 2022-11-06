#include<stdio.h>
#define Min(a,b) (a<b?a:b)
int n,a,b,l=0,lt=0,maxx=0;
main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&b);
		if(b==l)a++;
		else
		{
			if(a>=maxx&&lt>=maxx)maxx=Min(a,lt);
			lt=a;a=1;
		}
		l=b;
	}
	if(a>=maxx&&lt>=maxx)maxx=Min(a,lt);
	printf("%d",maxx<<1);
}