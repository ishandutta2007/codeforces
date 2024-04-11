#include<iostream>
#include<cstdio>
#include<unordered_map>
#define ll long long
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=14;
const int mod=1e9+7;
int qpow(int a,int b)
{
	int ret=1;
	for(;b;b>>=1)
	{
		if(b&1)ret=(ll)ret*a%mod;
		a=(ll)a*a%mod;
	}
	return ret;
}
int n;
int ans;
int a[maxn];
int cnt[1<<maxn],Log2[1<<maxn];
int winall[maxn][1<<maxn],win[maxn][maxn];
unordered_map<int,int>g[1<<maxn];int p[1<<maxn];
int main()
{
	n=read();
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)win[i][j]=(ll)a[i]*qpow(a[i]+a[j],mod-2)%mod;
	for(int i=0;i<n;i++)Log2[1<<i]=i;
	for(int i=0;i<n;i++)
	{
		winall[i][0]=1;
		for(int j=1;j<(1<<n);j++)winall[i][j]=(ll)winall[i][j-(j&(-j))]*win[i][Log2[j&(-j)]]%mod;
	}
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=i;j;j=(j-1)&i)
		{
			g[j][i]=1;
			for(int k=0;k<n;k++)if((j>>k)&1)g[j][i]=(ll)g[j][i]*winall[k][i-j]%mod;
		}
	}
	for(int i=1;i<(1<<n);i++)
	{
		p[i]=1;cnt[i]=cnt[i>>1]+(i&1);
		for(int j=(i-1)&i;j;j=(j-1)&i)p[i]=(p[i]-(ll)p[j]*g[j][i]%mod+mod)%mod;
		ans=(ans+(ll)p[i]*cnt[i]%mod*g[i][(1<<n)-1]%mod)%mod;
	}
	printf("%d",ans);
	return 0;
}