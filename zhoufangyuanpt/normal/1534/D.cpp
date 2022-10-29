#include<cstdio>
#include<cstring>
using namespace std;
int d[2100];
struct edge
{
	int x,y;
}e[2100];int len;
int main()
{
	int n;scanf("%d",&n);
	puts("? 1");
	fflush(stdout);
	int s1=0,s2=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(i!=1)
		{
			if(d[i]&1)s1++;
			else s2++;
		}
	}
	len=0;
	if(s1<s2)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]&1)
			{
				printf("? %d\n",i);
				fflush(stdout);
				for(int j=1;j<=n;j++)
				{
					int x;scanf("%d",&x);
					if(x==1)e[++len]=(edge){i,j};
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==1)e[++len]=(edge){1,i};
		}
		for(int i=2;i<=n;i++)
		{
			if((d[i]&1)==0)
			{
				printf("? %d\n",i);
				fflush(stdout);
				for(int j=1;j<=n;j++)
				{
					int x;scanf("%d",&x);
					if(x==1)e[++len]=(edge){i,j};
				}
			}
		}
	}
	puts("!");
	for(int i=1;i<=len;i++)
	{
		printf("%d %d\n",e[i].x,e[i].y);
	}
	fflush(stdout);
	return 0;
}