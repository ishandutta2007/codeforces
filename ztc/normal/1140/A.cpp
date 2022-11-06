#include<stdio.h>
int a,n,l,cnt=0;
main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a>l)l=a;
		if(i>=l)cnt++,l=i+1;
	}
	printf("%d",cnt);
}