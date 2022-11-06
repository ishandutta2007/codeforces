#include<stdio.h>
int a,b,c,n,t,g,h=998244353;
main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>t)c=a-t;
		else c=((t-a)%b)?(b-(t-a)%b):0;
		if(c<h)
		{
			g=i;
			h=c;
		}
	}
	printf("%d",g);
}