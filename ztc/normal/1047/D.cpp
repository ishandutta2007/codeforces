#include<stdio.h>
long long a,b;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	if(a>b)a^=(b^=(a^=b));
	if(a>=3){printf("%I64d",a*b-((a*b)&1));return 0;}
	if(a==1)printf("%I64d",(b/6)*6+(b%6>=4)*(b%6-3)*2);
	else
	{
		if(b==2)printf("0");
		else
		{
			if(b==3||b==7)printf("%I64d",a*b-2);
			else printf("%I64d",a*b);
		}
	}
}