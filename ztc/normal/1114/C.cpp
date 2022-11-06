#include<stdio.h>
#include<queue>
long long a[102][2],n,b,tot=0,maxx,cnt,h;
main()
{
	scanf("%lld%lld",&n,&b);maxx=n*2;
	for(long long i=2;i*i<=b;i++)
	{
		if(b%i==0)
		{
			a[++tot][0]=i;
			while(b%i==0)
			{
				b/=i;
				a[tot][1]++;
			}
		}
	}if(b!=1)
	{
		a[++tot][0]=b;a[tot][1]=1;
	}
	for(int i=1;i<=tot;i++)
	{
		cnt=0;h=n;
		while(h)cnt+=(h/=a[i][0]);cnt/=a[i][1];
		if(cnt<maxx)maxx=cnt;
	}printf("%lld",maxx);
}