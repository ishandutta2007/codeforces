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
int x,y;
int main()
{
	T=read();
	while(T--)
	{
		x=read();y=read();
		printf("%d\n",x<=y?y-(y%x)/2:x+y);
	}
	return 0;
}