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
int n;
int main()
{
	T=read();
	while(T--)
	{
		int n=read();
		for(int i=2;i<=n+1;i++)printf("%d ",i);putchar('\n');
	}
	return 0;
}