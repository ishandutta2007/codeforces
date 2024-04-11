#include<stdio.h>
int t,dep;bool z;
long long a,b,m,lb,rb,ls,rs,k,s[52];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&m);
		if(b<a)
		{
			printf("-1\n");
			continue;
		}
		if(b==a)
		{
			printf("1 %lld\n",a);
			continue;
		}
		lb=rb=ls=rs=a;dep=1;z=0;
		while(1)
		{
			lb=ls+1;ls+=lb;
			rb=rs+m;rs+=rb;
			dep++;
			if(rb>=b)break;
		}
		if(lb>b||dep>50)
		{
			printf("-1\n");
			continue;
		}
		printf("%d %lld ",dep,a);lb=ls=a;s[dep-1]=b-m;
		for(int i=dep-2;i>=1;i--)s[i]=s[i+1]<=0?0:s[i+1]-m+1>>1;
		for(int i=2;i<dep;i++)
		{
			if((ls<<1)+1>=s[i])
			{
				lb=ls+1;
				ls=ls<<1|1;
			}
			else
			{
				lb=s[i]-ls;
				ls=s[i];
			}
			printf("%lld ",lb);
		}
		if(dep>=2)printf("%lld",b);
		putchar('\n');
	}
}