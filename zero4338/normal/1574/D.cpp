#include<iostream>
#include<cstdio>
#include<unordered_map>
typedef unsigned long long ull;
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=11;
const int maxm=2e5+5;
const ull p=13331;
int n,m;
int a[maxn][maxm],c[maxn];
int b[maxm][maxn];
int ansv,ans[maxn];bool flag;
int now[maxn];
unordered_map<int,bool>exi;
bool check()
{
	ull bas=1,ret=0;
	for(int i=1;i<=n;i++)ret+=bas*now[i],bas*=p;
	return exi.find(ret)==exi.end();
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		for(int j=1;j<=c[i];j++)a[i][j]=read();
	}
	m=read();flag=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)b[i][j]=read();
		ull bas=1,ret=0;
		for(int j=1;j<=n;j++)ret+=bas*b[i][j],bas*=p;
		exi[ret]=1;
		if(flag)continue;
		flag=1;
		for(int j=1;j<=n;j++)if(b[i][j]!=c[j])flag=0;
	}
	if(!flag)for(int i=1;i<=n;i++)ans[i]=c[i];
	else
	{
		for(int i=1;i<=m;i++)
		{
			int sum=0;
			for(int j=1;j<=n;j++)now[j]=b[i][j],sum+=a[j][b[i][j]];
			for(int j=1;j<=n;j++)
			{
				if(b[i][j]>1&&sum-a[j][b[i][j]]+a[j][b[i][j]-1]>ansv)
				{
					now[j]--;
					if(check())
					{
						ansv=sum-a[j][b[i][j]]+a[j][b[i][j]-1];
						for(int k=1;k<=n;k++)ans[k]=b[i][k];ans[j]--;
					}
					now[j]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;	
}