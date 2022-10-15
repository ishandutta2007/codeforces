#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
int get(int x)
{
	return log10(x);
}
int main()
{
	T=read();
	while(T--)
	{
		int x1=read(),p1=read(),x2=read(),p2=read();
		int d1=log10(x1),d2=log10(x2);
		if(d1+p1!=d2+p2)putchar(d1+p1<d2+p2?'<':'>');
		else
		{
			for(int i=1;i<=d2-d1;i++)x1*=10;
			for(int i=1;i<=d1-d2;i++)x2*=10;
			if(x1!=x2)putchar(x1<x2?'<':'>');
			else putchar('=');
		}
		putchar('\n');
	}
	return 0;
}