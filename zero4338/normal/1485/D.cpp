#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int n,m;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x=read();
			if((i+j)&1)printf("720720 ");
			else printf("%d ",720720+x*x*x*x);
		}
		printf("\n");
	}
	return 0;
}