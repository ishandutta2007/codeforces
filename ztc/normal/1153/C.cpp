#include<stdio.h>
#define qwq(c) ((c=='?')?0:((c=='('?1:2)))
#define qaq ":("
int n,t=0,q=0,cnt=0;
int a[3000002];
char c;
main()
{
	scanf("%d",&n);
	if(n&1)return printf(qaq)&0;
	while((c=getchar())!='\n');
	for(int i=1;i<=n;i++)
	{
		c=getchar();
		a[i]=qwq(c);
		if(a[i]==1)t++;
	}
	t=(n>>1)-t;
	if(t<0)return printf(qaq)&0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(t)a[i]=1,t--;
			else a[i]=2;
		}
		if(a[i]==1)cnt++;
		else cnt--;
		if(cnt<=0&&i!=n)return printf(qaq)&0;
	}
	if(t)return printf(qaq)&0;
	for(int i=1;i<=n;i++)putchar(a[i]==1?'(':')');
}