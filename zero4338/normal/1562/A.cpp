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
int l,r;
int main()
{
	T=read();
	while(T--)
	{
		l=read();r=read();
		if(l*2>r)printf("%d\n",r-l);
		else printf("%d\n",(r-1)/2);
	}
	return 0;
}