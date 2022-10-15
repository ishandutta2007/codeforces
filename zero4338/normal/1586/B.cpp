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
const int maxn=1e5+5;
int T;
int n,m;
bool vis[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=m;i++){int a=read(),b=read(),c=read();vis[b]=1;}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				for(int j=1;j<=n;j++)if(i!=j)printf("%d %d\n",i,j);
				break;
			}
		}
	}
	return 0;
}