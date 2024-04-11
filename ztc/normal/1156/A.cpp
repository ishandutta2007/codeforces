#include<cstdio>
int qwq,a,l,t,cnt=0;
int main()
{
	scanf("%d",&qwq);
	while(qwq--)
	{
		scanf("%d",&a);
		if(a+l==5)
		{
		    printf("Infinite");
		    return 0;
		}
		if(l!=0)cnt+=(a==1?l+1:(a==2?3-(t==3):4));
		t=l;l=a;
	}
	printf("Finite\n%d",cnt);
}