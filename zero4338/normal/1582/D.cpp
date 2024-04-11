#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
int n;
int a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		if(n&1)
		{
			for(int i=1;i<=n-3;i+=2)printf("%d %d ",a[i+1],-a[i]);
			if(a[n-2]+a[n-1]!=0)printf("%d %d %d ",a[n],a[n],-a[n-2]-a[n-1]);
			else if(a[n-2]+a[n]!=0)printf("%d %d %d ",a[n-1],-a[n-2]-a[n],a[n-1]);
			else if(a[n-1]+a[n]!=0)printf("%d %d %d ",-a[n-1]-a[n],a[n-2],a[n-2]);
		}
		else for(int i=1;i<=n;i+=2)printf("%d %d ",a[i+1],-a[i]);
		printf("\n");
	}
	return 0;
}