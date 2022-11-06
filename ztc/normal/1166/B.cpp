#include<stdio.h>
int k,a,b;
int main()
{
	scanf("%d",&k);
	if(k<=24)return printf("-1")&0;
	for(int i=5;i<=k;i++)
	{
		if(k%i==0)
		{
			a=i;
			break;
		}
	}
	b=k/a;
	if(b<5)return printf("-1")&0;
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)
	{
		if((i+j)%5==1)putchar('a');
		else if((i+j)%5==2)putchar('e');
		else if((i+j)%5==3)putchar('i');
		else if((i+j)%5==4)putchar('o');
		else putchar('u');
	}
}