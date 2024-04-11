#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int T;
int n,a,b;
bool vis[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();a=read();b=read();
		if(abs(a-b)>1||a+b>n-2)puts("-1");
		else
		{
			for(int i=1;i<=n;i++)vis[i]=0;
			if(a==b)
			{

				for(int i=1;i<=a;i++)
				{
					printf("%d %d ",i,n-i+1);vis[i]=vis[n-i+1]=1;
				}
				for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);putchar('\n');
			}
			else if(a>b)
			{
				for(int i=1;i<=a;i++)
				{
					printf("%d %d ",n-2*a+i,n-i+1);vis[n-2*a+i]=vis[n-i+1]=1;
				}
				for(int i=n;i>=1;i--)if(!vis[i])printf("%d ",i);putchar('\n');
			}
			else
			{
				for(int i=1;i<=b;i++)
				{
					printf("%d %d ",2*b-i+1,i);vis[2*b-i+1]=vis[i]=1;
				}
				for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);putchar('\n');
			}
		}
	}
	return 0;
}