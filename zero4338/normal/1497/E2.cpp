#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=2e5+5;
const int maxm=1e7+5;
const int maxk=25;
int n,k;
int a[maxn];
int p[maxm],cnt,sq[maxm];bool vis[maxm];
void prework()
{
	sq[1]=1;
	for(int i=2;i<maxm;i++)
	{
		if(!vis[i]){p[++cnt]=i;sq[i]=i;}
		for(int j=1;j<=cnt&&p[j]*i<maxm;j++)
		{
			vis[i*p[j]]=1;
			if(sq[i]%p[j])sq[i*p[j]]=sq[i]*p[j];
			else sq[i*p[j]]=sq[i]/p[j];
			if(i%p[j]==0)break;
		}
	}
}
int ls[maxn][maxk],f[maxn][maxk];
int exi[maxm],sum;
void add(int x){exi[x]++;if(exi[x]>1)sum++;}
void del(int x){exi[x]--;if(exi[x])sum--;}
int main()
{
	T=read();prework();
	while(T--)
	{
		n=read();k=read();
		generate_n(a+1,n,[](){return sq[read()];});
		for(int i=0;i<=k;i++)
		{
			int p=1;
			for(int j=1;j<=n;j++)
			{
				add(a[j]);
				while(sum>i)del(a[p++]);
				ls[j][i]=p;
			}
			for(int j=1;j<=n;j++)exi[a[j]]=0;sum=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				f[i][j]=1e9;
				for(int l=0;l<=j;l++)f[i][j]=min(f[i][j],f[ls[i][l]-1][j-l]+1);
			}
		}
		printf("%d\n",f[n][k]);
	}
	return 0;
}