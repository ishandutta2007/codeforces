#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
int a,b,c;
int main()
{
	T=read();
	while(T--)
	{
		a=read();b=read();c=read();
		printf("%d\n",(a+c)&1);
	}
	return 0;
}