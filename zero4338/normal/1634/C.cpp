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
int n,k;
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();
		if((n*k/2)%k==0&&(n*k-n*k/2)%k==0)
		{
			puts("YES");
			for(int i=1;i<=n*k/2;i++){printf("%d ",2*i);if(i%k==0)putchar('\n');}
			for(int i=1;i<=n*k-n*k/2;i++){printf("%d ",2*i-1);if(i%k==0)putchar('\n');}
		}
		else puts("NO");
	}
	return 0;
}