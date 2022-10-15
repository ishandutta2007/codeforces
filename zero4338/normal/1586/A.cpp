#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=105;
const int maxm=2e4+5;
int n,a[maxn];
int id[maxn];
bool vis[maxm];
int p[maxm],cnt;
void prework()
{
	for(int i=2;i<maxm;i++)
	{
		if(!vis[i])p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<maxm;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	T=read();prework();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		if(vis[sum])
		{
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("%d ",i);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=n;i++)id[i]=i;
			sort(id+1,id+n+1,[](int i,int j){return a[i]<a[j];});
			for(int i=1;i<=n;i++)
			{
				if(vis[sum-a[id[i]]])
				{
					printf("%d\n",n-1);
					for(int j=1;j<id[i];j++)printf("%d ",j);
					for(int j=id[i]+1;j<=n;j++)printf("%d ",j);printf("\n");
					break;
				}
			}
		}
	}
}