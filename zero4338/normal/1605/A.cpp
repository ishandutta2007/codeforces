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
int a[4];
int main()
{
	T=read();
	while(T--)
	{
		a[1]=read();a[2]=read();a[3]=read();sort(a+1,a+4);
		if((a[1]+a[3]-2*a[2])%3)puts("1");
		else puts("0");
	}
	//
	return 0;
}