#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
int T,a,b,c;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int last=0;
		scanf("%d%d%d",&a,&b,&c);
		int now=0;
		if(b==0)
		{
			if(a!=0)for(int i=1;i<=a+1;++i)printf("0");
			else for(int i=1;i<=c+1;++i)printf("1");
			printf("\n");
			continue;
		}
		for(int i=1;i<=b;++i)
		{
			now^=1;
			printf("%d",now);
			last=now;
		}
		if(now==1)
		{
			for(int i=1;i<=c;++i)printf("1");
			for(int i=1;i<=a+1;++i)printf("0");
		}
		else 
		{
			for(int i=1;i<=a;++i)printf("0");
			for(int i=1;i<=c+1;++i)printf("1");
		}
		printf("\n");
	}
	return 0;
}