#include<stdio.h>
#include<iostream>
int n,a[1002],b[1002],cnt1=0,cnt2=0,p=0,q=0,s=0,t=0;
main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("? %d 1 %d %d\n",i,i,n);
		fflush(stdout);
		scanf("%d",&a[i]);cnt1+=(a[i]&=1);
	}
	for(int i=1;i<=n;i++)
	{
		printf("? 1 %d %d %d\n",i,n,i);
		fflush(stdout);
		scanf("%d",&b[i]);cnt2+=(b[i]&=1);
	}
	if(cnt1==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				if(s)t=i;
				else s=i;
			}
		}
		p=1;q=n;
		while(p<q)
		{
			printf("? %d %d %d %d\n",p,s,(p+q)>>1,s);
			fflush(stdout);
			scanf("%d",&cnt1);
			if(cnt1&1)q=(p+q)>>1;
			else p=(p+q+2)>>1;
		}
		printf("! %d %d %d %d",p,s,q,t);
	}
	else if(cnt2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				if(p)q=i;
				else p=i;
			}
		}
		s=1;t=n;
		while(s<t)
		{
			printf("? %d %d %d %d\n",p,s,p,(s+t)>>1);
			fflush(stdout);
			scanf("%d",&cnt1);
			if(cnt1&1)t=(s+t)>>1;
			else s=(s+t+2)>>1;
		}
		printf("! %d %d %d %d",p,s,q,t);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
		{
				if(p)q=i;
				else p=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				if(s)t=i;
				else s=i;
			}
		}
		printf("? %d %d %d %d\n",p,s,p,s);
		fflush(stdout);
		scanf("%d",&cnt1);
		if(cnt1&1)printf("! %d %d %d %d",p,s,q,t);
		else printf("! %d %d %d %d",p,t,q,s);
	}
}