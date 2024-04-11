#include<stdio.h>
int n,l,r,p;
main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&l,&r,&p);
		printf("%d\n",p<l?p:(r/p+1)*p);
	}
}