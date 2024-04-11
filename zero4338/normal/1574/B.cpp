#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
int a[3],m;
int main()
{
	T=read();
	while(T--)
	{
		a[0]=read();a[1]=read();a[2]=read();m=read();sort(a,a+3);
		int r=a[0]+a[1]+a[2]-3;
		int l=max(0,a[2]-a[1]-a[0]-1);
		if(m>=l&&m<=r)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}